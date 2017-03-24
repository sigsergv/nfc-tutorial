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

#ifndef _H_8166de26ce11fa4506028027f468f4a4
#define _H_8166de26ce11fa4506028027f468f4a4

const unsigned char CARD_SECTOR  = 0x5;
const unsigned char CARD_SECTOR_BLOCK = 0x2;
const unsigned char CARD_BLOCK = ((CARD_SECTOR * 4) + CARD_SECTOR_BLOCK);
const unsigned char CARD_SECTOR_TRAILER = ((CARD_SECTOR * 4) + 3);
const unsigned char DEFAULT_KEY_A[6] = {0xff, 0xff, 0xff, 0xff, 0xff, 0xff};
const unsigned char ACTIVE_KEY_A[6] = {0xaa, 0xbb, 0xcc, 0xdd, 0xee, 0xff};
const unsigned short INITIAL_BALANCE = 15000;
const unsigned short TICKET_PRICE = 170;

#define CHECK_BIT(value, b) (((value) >> (b))&1)

#endif