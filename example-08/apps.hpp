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

#ifndef _H_1e4b44de029cbfd06bf95196db89c17b
#define _H_1e4b44de029cbfd06bf95196db89c17b

#include <string>
#include <vector>

// see https://eftlab.co.uk/index.php/site-map/knowledge-base/211-emv-aid-rid-pix

const std::vector<std::string> KNOWN_APPLICATIONS = {
    "315041592E5359532E4444463031|Visa Payment System Environment - PSE (1PAY.SYS.DDF01)  ",
    "325041592E5359532E4444463031|Visa Proximity Payment System Environment - PPSE (2PAY.SYS.DDF01)  ",
    "44464D46412E44466172653234313031|DeviceFidelity In2Pay DFare applet  ",
    "A00000000101|MUSCLE Card Applet  ",
    "A000000003000000|(VISA) Card Manager GP",
    "A00000000300037561|Bonuscard  ",
    "A00000000305076010|VISA ELO Credit EMV",
    "A0000000031010|VISA Debit/Credit (Classic) EMV",
    "A000000003101001|VISA Credit EMV",
    "A000000003101002|VISA Debit EMV",
    "A0000000032010|VISA Electron EMV",
    "A0000000032020|VISA EMV",
    "A0000000033010|VISA Interlink EMV",
    "A0000000034010|VISA Specific EMV",
    "A0000000035010|VISA Specific EMV",
    "A000000003534441|Schlumberger Security Domain GP",
    "A0000000035350|Security Domain GP",
    "A000000003535041|Security Domain GP",
    "A0000000036010|Domestic Visa Cash Stored Value EMV",
    "A0000000036020|International Visa Cash Stored Value EMV",
    "A0000000038002|VISA Auth, VisaRemAuthen EMV-CAP (DPA) EMV",
    "A0000000038010|VISA Plus EMV",
    "A0000000039010|VISA Loyalty EMV",
    "A000000003999910|VISA Proprietary ATM EMV",
    "A0000000040000|MasterCard Card Manager GP",
    "A00000000401|MasterCard PayPass EMV",
    "A0000000041010|MasterCard Credit EMV",
    "A00000000410101213|MasterCard Credit EMV",
    "A00000000410101215|MasterCard Credit EMV",
    "A0000000041010BB5449435301|[UNKNOWN]  ",
    "A0000000042010|MasterCard Specific EMV",
    "A0000000042203|MasterCard Specific  ",
    "A0000000043010|MasterCard Specific EMV",
    "A0000000043060|Maestro (Debit) EMV",
    "A000000004306001|Maestro (Debit) EMV",
    "A0000000044010|MasterCard Specific EMV",
    "A0000000045010|MasterCard Specific EMV",
    "A0000000045555|APDULogger  ",
    "A0000000046000|Cirrus EMV",
    "A0000000048002|SecureCode Auth EMV-CAP EMV",
    "A0000000049999|MasterCard PayPass?? EMV",
    "A0000000050001|Maestro UK EMV",
    "A0000000050002|Solo EMV",
    "A0000000090001FF44FF1289|Orange  ",
    "A0000000101030|Maestro-CH  ",
    "A00000001800|Gemplus ?  ",
    "A0000000181001|com.gemplus.javacard.util packages  ",
    "A000000018434D|Gemplus card manager GP",
    "A000000018434D00|Gemplus Security Domain GP",
    "A00000002401|Self Service EMV",
    "A000000025|American Express EMV",
    "A0000000250000|American Express EMV",
    "A00000002501|American Express EMV",
    "A000000025010104|American Express  ",
    "A000000025010402|American Express EMV",
    "A000000025010701|ExpressPay EMV",
    "A000000025010801|American Express EMV",
    "A0000000291010|Link / American Express EMV",
    "A00000002945087510100000|CO-OP  ",
    "A00000002949034010100001|HSBC  ",
    "A00000002949282010100000|Barclay  ",
    "A000000029564182|HAFX  ",
    "A00000003029057000AD13100101FF|BelPIC (Belgian Personal Identity Card) JavaCard Applet  ",
    "A0000000308000000000280101|Gemalto .NET Card AID  ",
    "A0000000421010|Cartes Bancaire EMV Card EMV",
    "A0000000422010|  EMV",
    "A0000000423010|  EMV",
    "A0000000424010|  EMV",
    "A0000000425010|  EMV",
    "A00000005945430100|Girocard Electronic Cash  ",
    "A000000063504B43532D3135|PKCS-15  ",
    "A0000000635741502D57494D|WAP-WIM  ",
    "A00000006510|JCB EMV",
    "A0000000651010|JCB J Smart Credit EMV",
    "A00000006900|Moneo EMV",
    "A000000077010000021000000000003B|Visa AEPN EMV",
    "A0000000790100|CACv2 PKI ID  ",
    "A0000000790101|CACv2 PKI Sign  ",
    "A0000000790102|CACv2 PKI Enc  ",
    "A00000007901F0|CACv1 PKI Identity Key  ",
    "A00000007901F1|CACv1 PKI Digital Signature Key  ",
    "A00000007901F2|CACv1 PKI Key Management Key  ",
    "A0000000790200|CACv2 DoD Person  ",
    "A0000000790201|CACv2 DoD Personnel  ",
    "A00000007902FB|CACv1 BC  ",
    "A00000007902FD|CACv1 BC  ",
    "A00000007902FE|CACv1 BC  ",
    "A0000000790300|CACv2 Access Control Applet  ",
    "A0000000791201|CAC JDM  ",
    "A0000000791202|CAC JDM  ",
    "A0000000871002FF49FF0589|Telenor USIM USIM",
    "A00000008810200105C100|BuyPass BIDA BuyPass",
    "A000000088102201034221|BuyPass BEID (BuyPass Electronic ID?) BuyPass",
    "A000000088102201034321|BuyPass BEID (BuyPass Electronic ID?) BuyPass",
    "A0000000960200|Proton World International Security Domain GP",
    "A000000098|Debit Card EMV",
    "A0000000980840|Visa Common Debit  ",
    "A0000000980848|Debit Card EMV",
    "A0000001110101|Postcard  ",
    "A0000001160300|PIV CHUID  ",
    "A0000001166010|PIV Fingerprints  ",
    "A0000001166030|PIV Facial Image  ",
    "A0000001169000|PIV Security Object  ",
    "A000000116A001|PIV Authentication Key  ",
    "A000000116DB00|CCC  ",
    "A000000118010000|DF_Verkehr  ",
    "A000000118020000|DF_Partner  ",
    "A000000118030000|DF_Schülerdaten  ",
    "A000000118040000|DF_KEP_SIG  ",
    "A0000001184543|Digital Signature (SSCA)  ",
    "A000000118454E|Encryption Application  ",
    "A0000001211010|Dankort (VISA GEM Vision) EMV",
    "A0000001320001|org.javacardforum.javacard.biometry  ",
    "A0000001408001|eCode  ",
    "A0000001410001|PagoBANCOMAT EMV",
    "A0000001510000|Global Platform Security Domain AID GP",
    "A00000015153504341534400|CASD_AID GP",
    "A0000001523010|Discover EMV",
    "A0000001524010|Discover EMV",
    "A0000001544442|Banricompras Debito EMV",
    "A0000001570010|AMEX  ",
    "A0000001570020|MasterCard  ",
    "A0000001570021|Maestro  ",
    "A0000001570022|Maestro  ",
    "A0000001570023|CASH  ",
    "A0000001570030|VISA  ",
    "A0000001570031|VISA  ",
    "A0000001570040|JCB  ",
    "A0000001570050|Postcard  ",
    "A0000001570051|Postcard  ",
    "A0000001570100|MCard  ",
    "A0000001570104|MyOne  ",
    "A0000001570109|Mediamarkt Card  ",
    "A000000157010A|Gift Card  ",
    "A000000157010B|Bonuscard  ",
    "A000000157010C|WIRCard  ",
    "A000000157010D|Power Card  ",
    "A0000001574443|DINERS CLUB  ",
    "A0000001574444|Supercard Plus  ",
    "A000000167413000FF|JCOP Identify Applet JCOP",
    "A000000167413001|FIPS 140-2  ",
    "A000000172950001|BAROC Financial Application Taiwan EMV",
    "A000000177504B43532D3135|BelPIC (Belgian Personal Identity Card)  ",
    "A0000001850002|UK Post Office Account card EMV",
    "A0000001884443|DINERS CLUB  ",
    "A0000002040000|?  ",
    "A0000002281010|SPAN (M/Chip) EMV",
    "A0000002282010|SPAN (VIS) EMV",
    "A00000022820101010|SPAN  ",
    "A0000002471001|Machine Readable Travel Documents (MRTD) MRTD",
    "A0000002472001|Machine Readable Travel Documents (MRTD) MRTD",
    "A0000002771010|INTERAC EMV",
    "A00000030600000000000000|PC/SC Initial access data AID  ",
    "A000000308000010000100|Personal Identity Verification (PIV) / ID-ONE PIV BIO  ",
    "A00000031510100528|Currence PuC EMV",
    "A0000003156020|Chipknip EMV",
    "A00000032301|MUSCLE Applet Package  ",
    "A0000003230101|MUSCLE Applet Instance  ",
    "A0000003241010|Discover Expresspay (ZIP)  ",
    "A000000333010101|UnionPay Debit  ",
    "A000000333010102|UnionPay Credit  ",
    "A000000333010103|UnionPay Quasi Credit  ",
    "A000000333010106|UnionPay Electronic Cash  ",
    "A0000003591010|   ",
    "A0000003591010028001|Girocard EAPS EMV",
    "A00000035910100380|   ",
    "A0000003660001|Postamat  ",
    "A0000003660002|Postamat VISA  ",
    "A0000003710001|InterSwitch Verve Card EMV",
    "A0000003964D66344D0002|MIFARE4MOBILE  ",
    "A00000039742544659|Microsoft IDMP AID  ",
    "A0000003974349445F0100|Microsoft PNP AID  ",
    "A0000004271010|Hiperchip  ",
    "A0000004320001|Universal Electronic Card  ",
    "A0000004360100|Ticket Restaurant  ",
    "A0000004391010|Exchange ATM card  ",
    "A0000004540010|Etranzact Genesis Card EMV",
    "A0000004540011|Etranzact Genesis Card 2 EMV",
    "A0000004762010|GOOGLE_CONTROLLER_AID  ",
    "A0000004763030|GOOGLE_MIFARE_MANAGER_AID  ",
    "A0000004766C|GOOGLE_PAYMENT_AID EMV",
    "A000000476A010|GSD_MANAGER_AID GP",
    "A000000476A110|GSD_MANAGER_AID GP",
    "A000000485|Softcard SmartTap  ",
    "A0000005241010|RuPay EMV",
    "A0000005271002|Yubikey NEO U2F Demo applet YKNEO",
    "A000000527200101|Yubikey NEO Yubikey2 applet interface YKNEO",
    "A000000527210101|Yubikey NEO OATH Applet YKNEO",
    "A0000005591010FFFFFFFF8900000100|ISD-R Application. Used as TAR.  ",
    "A0000005591010FFFFFFFF8900000200|ECASD Application. Used as TAR.  ",
    "A0000005591010FFFFFFFF8900000D00|ISD-P Executable Load File.  ",
    "A0000005591010FFFFFFFF8900000E00|ISD-P Executable Module.  ",
    "A0000005591010FFFFFFFF8900000F00|Reserved value for the Profile's ISD-P  ",
    "A0000005591010FFFFFFFF8900001000|ISD-P Application ('1010FFFFFFFF89000010' to '1010FFFFFFFF8900FFFF'. Used as TAR. The value is allocated during the 'Profile Download and Installation procedure'  ",
    "A00000061700|Fidesmo javacard  ",
    "A0000006200620|Debit Network Alliance (DNA)  ",
    "A0000006581010|MIR Credit  ",
    "A0000006582010|MIR Debit  ",
    "A0000006723010|TROY chip credit card EMV",
    "A0000006723020|TROY chip debit card EMV",
    "B012345678|Maestro TEST EMV",
    "D040000001000002|Paylife Quick (IEP). Preloaded Electronic Purse  ",
    "D040000002000002|RFU  ",
    "D040000003000002|POS  ",
    "D040000004000002|ATM  ",
    "D04000000B000002|Retail  ",
    "D04000000C000002|Bank_Data  ",
    "D04000000D000002|Shopping  ",
    "D040000013000001|DF_UNI_Kepler1  ",
    "D040000013000001|DF_Schüler1  ",
    "D040000013000002|DF_UNI_Kepler2  ",
    "D040000013000002|DF_Schüler2  ",
    "D040000014000001|DF_Mensa  ",
    "D040000015000001|DF_UNI_Ausweis  ",
    "D040000015000001|DF_Ausweis  ",
    "D0400000190001|EMV ATM Maestro  ",
    "D0400000190002|EMV POS Maestro  ",
    "D0400000190003|EMV ATM MasterCard  ",
    "D0400000190004|EMV POS MasterCard  ",
    "D0400000190010|Digital ID  ",
    "D276000005|   ",
    "D276000005AA040360010410|G D App Nokia 6212  ",
    "D276000005AA0503E00401|G D App Nokia 6212  ",
    "D276000005AA0503E00501|G D App Nokia 6212  ",
    "D276000005AA0503E0050101|G D App Nokia 6212  ",
    "D276000005AB0503E0040101|G D App Nokia 6212  ",
    "D27600002200000001|SCT LOYALTY  ",
    "D27600002200000002|BUSINESS CARD  ",
    "D27600002200000060|PKCS#11 Token  ",
    "D276000025|Girocard  ",
    "D27600002545410100|   ",
    "D27600002545500100|Girocard EMV",
    "D27600002547410100|Girocard ATM  ",
    "D276000060|   ",
    "D2760000850100|NDEF Tag Application / Mifare DESFire Tag Application  ",
    "D2760000850101|NDEF Tag Application  ",
    "D276000118|   ",
    "D2760001180101|Giesecke &amp  ",
    "D27600012401|OpenPGP Card OpenPGP",
    "D276000124010101FFFF000000010000|OpenPGP Card OpenPGP",
    "D2760001240102000000000000010000|OpenPGP Card OpenPGP",
    "D27600012402|SmartChess SmartChess",
    "D2760001240200010000000000000000|SmartChess SmartChess",
    "D4100000011010|   ",
    "D5280050218002|? EMV",
    "D5780000021010|Bankaxept EMV",
    "D7560000010101|Reka Card  ",
    "D7560000300101|M Budget  ",
    "E80704007F00070302|nPA  ",
    "E82881C11702|AlphaCard application  ",
    "E828BD080F|ISO-7816-15 EF.DIR  ",
    "F0000000030001|BRADESCO EMV",

    // some additional items
    "A000000151000000|Default Card Manager (GP)",
    "A000000432554543495344|UEK Main Security Domain",
    "A00000043255454353534431|UEK Secondary Security Domain" // see http://www.uecard.ru/upload/files/pdf/ps-uek/pravila-fuo/2-1/ОД-10_Спецификация_УЭК_2.1.pdf
};


#endif