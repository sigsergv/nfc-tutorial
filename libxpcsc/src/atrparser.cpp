/*
 * Copyright (c) 2017, Sergey Stolyarov <sergei@regolit.com>
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *     * Redistributions of source code must retain the above copyright
 *       notice, this list of conditions and the following disclaimer.
 *     * Redistributions in binary form must reproduce the above copyright
 *       notice, this list of conditions and the following disclaimer in the
 *       documentation and/or other materials provided with the distribution.
 *     * Neither the name of the <organization> nor the
 *       names of its contributors may be used to endorse or promote products
 *       derived from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL <COPYRIGHT HOLDER> BE LIABLE FOR ANY
 * DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
 * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

/**
 * @file atr_parser.cpp
 * @author Sergey Stolyarov <sergei@regolit.com>
 */

#include <iostream>
#include <stdexcept>
#include <sstream>
#include <map>


#include "../include/xpcsc.hpp"
#include "debug.hpp"

namespace xpcsc {

// high nibble, XY -> X
#define HN(x) ((x>>4) & 0xf)

// low nibble, XY -> Y
#define LN(x) (x & 0xf)

// check bit: 1,2,...
#define CHECK_BIT(value, b) (((value) >> (b-1))&1)


ATRParseError::ATRParseError(const char * what)
    : std::runtime_error(what)
{}

typedef enum {ATRNONE, TS, T0, TA1, TB1, TC1, TD1, 
    TA2, TB2, TC2, TD2, 
    TA3, TB3, TC3, TD3,
    TA4, TB4, TC4, TD4,
    TA5, TB5, TC5, TD5,
    TA6, TB6, TC6, TD6,
    TA7, TB7, TC7, TD7,
    TCK } ATRField;

struct ATRParser::Private
{
    Bytes atr;

    // common fields (like interface bytes)
    std::map<ATRField, unsigned char> fields;

    // historical bytes
    unsigned char hb[15];
    size_t hb_size;
};


ATRParser::ATRParser()
{
    p = new Private;
}

ATRParser::ATRParser(const Bytes & bytes)
{
    p = new Private;

    load(bytes);
}


void ATRParser::load(const Bytes & bytes)
{
    size_t size = bytes.size();

    if (size > 33) {
        throw ATRParseError("too long");
    }

    if (size < 2) {
        throw ATRParseError("too short");
    }

    p->atr.assign(bytes);
    p->fields.clear();

    unsigned char pos = 0;
    unsigned char b;
    unsigned char mn;

    // byte: TS
    b = bytes.at(pos);
    if (b != 0x3b && b != 0x3f) {
        throw ATRParseError("Invalid TS");
    }
    p->fields[TS] = b;
    pos++;

    // byte: T0
    b = bytes.at(pos);
    p->fields[T0] = b;

    // historical bytes, up to 15
    p->hb_size = LN(b); 

    // read next sections
    unsigned char TD_p = b;

    // all section keys
    ATRField sections_TA[] = {ATRNONE, TA1, TA2, TA3, TA4, TA5, TA6, TA7};
    ATRField sections_TB[] = {ATRNONE, TB1, TB2, TB3, TB4, TB5, TB6, TB7};
    ATRField sections_TC[] = {ATRNONE, TC1, TC2, TC3, TC4, TC5, TC6, TC7};
    ATRField sections_TD[] = {ATRNONE, TD1, TD2, TD3, TD4, TD5, TD6, TD7};

    // index of current section
    size_t i = 1;

    while (1) {
        if (i > 7) {
            throw ATRParseError("too much interface bytes");
        }
        // check presense of TAi
        if (CHECK_BIT(TD_p, 5)) {
            // next byte is TAi, remember it
            pos++;
            b = bytes.at(pos);
            p->fields[sections_TA[i]] = b;
        }
        // check presense of TBi
        if (CHECK_BIT(TD_p, 6)) {
            // next byte is TBi, remember it
            pos++;
            b = bytes.at(pos);
            p->fields[sections_TB[i]] = b;
        }
        // check presense of TCi
        if (CHECK_BIT(TD_p, 7)) {
            // next byte is TCi, remember it
            pos++;
            b = bytes.at(pos);
            p->fields[sections_TC[i]] = b;
        }
        // check presense of TDi
        if (CHECK_BIT(TD_p, 8)) {
            // next byte is TCi, remember it
            pos++;
            b = bytes.at(pos);
            p->fields[sections_TD[i]] = b;
            PRINT_DEBUG("[D] TD" << i << " is set");
            TD_p = b;
        } else {
            // no more interface bytes
            PRINT_DEBUG("[D] no more bytes, pass " << i);
            break;
        }
        i++;
    }

    if (pos > size - p->hb_size - 1) {
        // PRINT_DEBUG("[E] position " << int(pos));
        // PRINT_DEBUG("[E] HB size " << int(p->hb_size));
        // PRINT_DEBUG("[E] size " << int(size));
        throw ATRParseError("too short, no place for historical bytes");
    }

    // store historical bytes
    for (i=0; i<p->hb_size; i++) {
        pos++;
        b = bytes.at(pos);
        (p->hb)[i] = b;
    }

    // check final checksum byte
    if (pos == size-2) {
        // read TCK byte
        pos++;
        b = bytes.at(pos);
        p->fields[TCK] = b;
    } else if (pos >= size) {
        throw ATRParseError("Incorrect ATR structure: actual size don't match calculated");
    }
    // PRINT_DEBUG("[E] position " << int(pos));
    // PRINT_DEBUG("[E] size " << int(size));

    mn = HN(b);
}

ATRParser::~ATRParser()
{
    delete p;
}

std::string ATRParser::str() const
{
    std::stringstream ss;
    std::stringstream sd;
    std::map<ATRField, unsigned char>::const_iterator end = p->fields.end();
    unsigned char b;

    PRINT_DEBUG("[D] Parsed fields: " << p->fields.size());

    // try to detect PICC, see section 3.1.3.2.3.1 of PC/SC specification
    bool is_picc = false;
    if (p->fields[TS] == 0x3b && HN(p->fields[T0]) == 0x8 
        && p->fields[TD1] == 0x80 && p->fields[TD2] == 0x01)
    {
        ss << "  Proxymity card detected.";
        ss << '\n';
        is_picc = true;
    }

    b = p->fields[TS];
    ss << "  Format byte TS=";
    switch (b) {
    case 0x3b:
        ss << "3B: direct convention";
        break;
    case 0x3f:
        ss << "3F: inverse convention";
        break;
    }
    ss << '\n';

    if (p->fields.find(TD1) != end) {
        b = p->fields[TD1];
        ss << "  TD1=" << format(b);
        switch (LN(b)) {
        case 1:
            ss << ", protocol T=1";
            break;
        case 0:
            ss << ", protocol T=0";
            break;
        }
        ss << '\n';
    }

    float f_max[] = {4, 5, 6, 8, 12, 16, 20, -1, -1, 5, 7.5, 10, 15, 20, 0, 0};
    int fi[] = {372, 372, 558, 744, 1116, 1488, 1860, -1, -1, 512, 768, 1024,   1536,   2048, -1, -1};
    int Di[] = {-1, 1, 2, 4, 8, 16, 32, 64, 12, 20, -1, -1, -1, -1, -1, -1};

    if (p->fields.find(TA1) != end) {
        b = p->fields[TA1];
        ss << "  TA1=" << format(b) << ": ";

        ss << "f_max=" << f_max[HN(b)] << ", Fi=" << fi[HN(b)] << ", Di=" << Di[LN(b)];
        ss << '\n';
    }

    if (p->fields.find(TB1) != end) {
        b = p->fields[TB1];
        ss << "  TB1=" << format(b);
        ss << '\n';
    }

    if (p->fields.find(TC1) != end) {
        b = p->fields[TC1];
        ss << "  TC1=" << format(b);
        ss << ", EGTi=" << format(b);
        ss << '\n';
    }

    if (p->fields.find(TD2) != end) {
        b = p->fields[TD2];
        ss << "  TD2=" << format(b);
        switch (LN(b)) {
        case 1:
            ss << ", protocol T=1";
            break;
        case 0:
            ss << ", protocol T=0";
            break;
        }
        ss << '\n';
    }

    if (p->fields.find(TA2) != end) {
        b = p->fields[TA2];
        ss << "  TA2=" << format(b) << ": ";

        ss << "f_max=" << f_max[HN(b)] << ", Fi=" << fi[HN(b)] << ", Di=" << Di[LN(b)];
        ss << '\n';
    }

    if (p->fields.find(TC2) != end) {
        b = p->fields[TC2];
        ss << "  TC2=" << format(b);
        ss << ", EGTi=" << format(b);
        ss << '\n';
    }

    // we don't care about TA2, TA3 etc

    // historical bytes
    ss << "  Historical bytes size: " << p->hb_size;
    // try to parse historical bytes
    if (!is_picc) {
        ss << ", proprietary format.";
    } else {
        ss << "";
    }
    ss << '\n';

    if (p->hb_size > 0) {
        Bytes hb(p->hb, p->hb_size);
        ss << "  Historical bytes: " << format(hb) << '\n';

        // we can parse PICC historical data
        if (is_picc) {
            if (hb.at(0) == 0x80) {
                if (p->hb_size >= 2 && hb.at(1) == 0x4f) {
                    ss << "  PICC application detected" << '\n';
                    // int hbaid_length = hb.at(2);
                    // next 5 bytes defines  RID
                    Bytes RID = hb.substr(3, 5);
                    ss << "    RID=" << format(RID) << '\n';
                    unsigned char SS = hb.at(8);
                    ss << "    SS=" << format(SS) << '\n';
                    Bytes CardName = hb.substr(9, 2);
                    ss << "    CardName=" << format(CardName) << '\n';
                } else {
                    ss << "  TLV data" << '\n';
                    size_t i = 1;
                    size_t max_i = hb.size();
                    while (1) {
                        if (i >= max_i) {
                            break;
                        }
                        unsigned char tag = HN(hb.at(i));
                        unsigned char length = LN(hb.at(i));

                        switch (tag) {
                        case 0x3:
                            ss << "    Card service data byte (tag 0x3)";
                            break;
                        case 0x4:
                            ss << "    Initial access data (tag 0x4)";
                            break;
                        case 0x5:
                            ss << "    Card issuer data (tag 0x5)";
                            break;
                        case 0x6:
                            ss << "    Pre-issuing data (tag 0x6)";
                            break;
                        case 0x7:
                            ss << "    Card capabilities (tag 0x7)";
                            break;
                        case 0x8:
                            ss << "    Status indicator (tag 0x8)";
                            break;
                        default:
                            ss << "    tag: " << format(tag);
                        }
                        
                        // read next "length" bytes
                        size_t next_pos = i+length+1;
                        ss << "; bytes:";
                        i++;
                        for (;i<next_pos;i++) {
                            ss << " " << format(hb.at(i));
                        }
                        ss << '\n';
                    }
                }
            }
        }
    }

    // TCK
    if (p->fields.find(TCK) != end) {
        // found TCK, check 
        ss << "  TCK found: " << format(p->fields[TCK]);
        unsigned char checksum = p->fields[TCK];

        size_t max = p->atr.size() - 1;
        for (size_t i=1; i<max; i++) {
            checksum ^= p->atr.at(i);
        }

        if (checksum == 0) {
            ss << ", matches";
        } else {
            ss << ", doesn't match!";
        }
        ss << '\n';
    } else {
        ss << "  No TCK present" << '\n';
    }

    return ss.str();
    // return sd.str() + ss.str();
}

}
