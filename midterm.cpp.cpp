#include <bitset>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>

/**
 *  ��X���~�T���C
 *
 *  @param const std::string& cmd   �{������ɪ��W��
 *  @return none.
 *  @since  0.1.0
 **/
void error(const std::string& cmd, const std::string& msg) {
    std::cout << "Error: " << msg << std::endl;
    std::cout << " type '" << cmd << " -?' to see usage." << std::endl;

    exit(-1);
} // error()

/**
 *  �L�X�Q�i���ഫ���ܦr��C�غc�ÿ�X�@�Ӯ榡��:
 *    Decimal number #dec in #base: #num
 *  �����ܦr��F�䤤:
 *      #dec  �N��Q�i��Ʀr�r��F
 *      #base �O�ഫ�� (base)�A�p�G�i�A�K�i��F
 *      #num  �O�ഫ��Ʀr�r��
 *  @param const std::string& dec   �Q�i��Ʀr�r��
 *  @param const std::string& base  �Ʀr�򩳦r��
 *  @param const std::string& num   �ഫ��Ʀr�r��
 *  @return None.
 *  @since  0.1.0
 **/
void numInBase(
    const std::string& dec,
    const std::string& base,
    const std::string& num
) {
    std::cout
        << "Decimal number "
        << dec
        << base
        << num
        << std::endl;
} // numInBase

/**
 *  �N�Q�i��Ʀr�r���ഫ���G�i��Ʀr�r��C
 *
 *  @param const std::string& dec   �Q�i��Ʀr�r��
 *  @return std::string             �G�i��Ʀr�r��
 *  @since  0.1.0
 **/
std::string dec2bin(const std::string& dec) {
    std::stringstream bin;

    bin << std::bitset<16>(std::stoi(dec));

    numInBase(dec, " in 16 bits binary: ", bin.str());

    return bin.str();
} // decToBin()

/**
 *  �N�Q�i��Ʀr�r���ഫ���Q���i��Ʀr�r��C
 *
 *  @param const std::string& dec   �Q�i��Ʀr�r��
 *  @return std::string             �Q���i��Ʀr�r��
 *  @since  0.1.0
 **/
std::string dec2hex(const std::string& dec) {
    std::stringstream hex;

    hex << "0x" << std::hex << std::stoi(dec);

    numInBase(dec, " in hexadecimal: ", hex.str());

    return hex.str();
} // decToHex()

/**
 *  �N�Q�i��Ʀr�r���ഫ���K�i��Ʀr�r��C
 *
 *  @param const std::string& dec   �Q�i��Ʀr�r��
 *  @return std::string             �K�i��Ʀr�r��
 *  @since  0.1.0
 **/
std::string dec2oct(const std::string& dec) {
    std::stringstream oct;

    oct << "0" << std::oct << std::stoi(dec);

    numInBase(dec, " in octal: ", oct.str());

    return oct.str();
} // decToOct()

/**
 *  �L�X�ഫ�Q�i��ܦr��C�غc�ÿ�X�@�Ӯ榡��:
 *    #base number #num in decimal: #dec
 *  �����ܦr��F�䤤:
 *      #base �O�Ʀr�� (base)�A�p�G�i�A�K�i��F
 *      #num  �O�Ʀr�r��
 *      #dec  �N��Q�i��Ʀr�r��F
 *  @param const std::string& base  �Ʀr�򩳦r��
 *  @param const std::string& num   �Ʀr�r��
 *  @param const std::string& dec   �Q�i��Ʀr�r��
 *  @return None.
 *  @since  0.1.0
 **/
void numInDec(
    const std::string& base,
    const std::string& num,
    const std::string& dec
) {
    std::cout
        << base
        << " number "
        << num
        << " in decimal: "
        << dec
        << std::endl;
} // numInDec()

/**
 *  �N�G�i��Ʀr�r���ഫ���Q�i��Ʀr�r��C
 *
 *  @param const std::string& bin   �G�i��Ʀr�r��
 *  @return std::string             �Q�i��Ʀr�r��
 *  @since  0.1.0
 **/
std::string bin2dec(const std::string& bin) {
    std::stringstream dec;

    dec << std::stol(bin, nullptr, 2);

    numInDec("Binary", bin, dec.str());

    return dec.str();
} // bin2dec()

/**
 *  �N�K�i��Ʀr�r���ഫ���Q�i��Ʀr�r��C
 *
 *  @param const std::string& oct   �K�i��Ʀr�r��
 *  @return std::string             �Q�i��Ʀr�r��
 *  @since  0.1.0
 **/
std::string oct2dec(const std::string& oct) {
    std::stringstream dec;

    dec << std::stol(oct, nullptr, 8);

    numInDec("Octal", oct, dec.str());

    return dec.str();
} // oct2dec()

/**
 *  �N�Q���i��Ʀr�r���ഫ���Q�i��Ʀr�r��C
 *
 *  @param const std::string& hex   �Q���i��Ʀr�r��
 *  @return std::string             �Q�i��Ʀr�r��
 *  @since  0.1.0
 **/
std::string hex2dec(const std::string& hex) {
    std::stringstream dec;

    dec << std::stol(hex, nullptr, 16);

    numInDec("Hexadecimal", hex, dec.str());

    return dec.str();
} // hex2dec()

/**
 *  �ˬd *str* �O���O�Ʀr�r��C�Q�� C++ �� stol (string-to-long)
 *  ����ˬd��J���r��O���O�X�z�� *�Ʀr�r��*�C
 *
 *  @param const std::string& str   �n�ˬd���r��
 *  @return bool    true    �X�k���Ʀr�r��
 *                  false   �t���D�Ʀr�r�����r��
 *  @since  0.1.0
 **/
bool is_number(const std::string& str, int base = 10) {
    size_t sz;

    try {
        std::stol(str, &sz, base);
    }
    catch (const std::invalid_argument& e) {
        ;
    }

    return (sz == str.length());
} // is_number()

/**
 *  �Q�i��-�G�i��Ʀr�����ഫ���ը�ơC
 *
 *  @param const std::string& dec   �Q�i��Ʀr�r��
 *  @return none.
 *  @since  0.1.0
 **/
bool test_dec_bin(const std::string& cmd, const std::string& dec) {
    std::string bin;
    std::string num;

    std::cout << "C:\\" << cmd << " -b " << dec << std::endl;
    bin = dec2bin(dec);

    std::cout << "C:\\" << cmd << " -B " << num << std::endl;
    num = bin2dec(bin);

    std::cout << std::endl;

    return (dec == num);
} // test_dec_bin();

/**
 *  �Q�i��-�Q���i��Ʀr�����ഫ���ը�ơC
 *
 *  @param const std::string& dec   �Q�i��Ʀr�r��
 *  @return none.
 *  @since  0.1.0
 **/
bool test_dec_hex(const std::string& cmd, const std::string& dec) {
    std::string hex;
    std::string num;

    std::cout << "C:\\" << cmd << " -h " << dec << std::endl;
    hex = dec2hex(dec);

    std::cout << "C:\\" << cmd << " -H " << num << std::endl;
    num = hex2dec(hex);

    std::cout << std::endl;

    return (dec == num);
} // test_dec_hex();

/**
 *  �Q�i��-�K�i��Ʀr�����ഫ���ը�ơC
 *
 *  @param const std::string& dec   �Q�i��Ʀr�r��
 *  @return none.
 *  @since  0.1.0
 **/
bool test_dec_oct(const std::string& cmd, const std::string& dec) {
    std::string oct;
    std::string num;

    std::cout << "C:\\" << cmd << " -o " << dec << std::endl;
    oct = dec2oct(dec);

    std::cout << "C:\\" << cmd << " -O " << num << std::endl;
    num = oct2dec(oct);

    std::cout << std::endl;

    return (dec == num);
} // test_dec_oct();

/**
 *  ��X�{���ϥνd�ҡC
 *
 *  @param const std::string& cmd   �{������ɪ��W��
 *  @param const std::string& dec   �Q�i��Ʀr�r��
 *  @return none.
 *  @since  0.1.0
 **/
void sample_usage(const std::string& cmd, const std::string& dec) {
    std::cout << "Examples: " << std::endl << std::endl;

    test_dec_bin(cmd, dec) ? (void)0 : error(cmd, "Dec-Bin converting error!");
    test_dec_hex(cmd, dec) ? (void)0 : error(cmd, "Dec-Hex converting error!");
    test_dec_oct(cmd, dec) ? (void)0 : error(cmd, "Dec-Oct converting error!");
} // sample_usage()

/**
 *  ��X�{���ϥλ����C
 *
 *  @param const std::string& cmd   �{������ɪ��W��
 *  @return none.
 *  @since  0.1.0
 **/
void usage(const std::string& cmd) {
    std::string num;

    std::cout << cmd << " v0.1.0 " << std::endl;
    std::cout << "usage: " << std::endl;
    std::cout << " -H hexadecimal to decimal." << std::endl;
    std::cout << " -h decimal to hexadecimal." << std::endl;
    std::cout << " -O octal to decimal." << std::endl;
    std::cout << " -o decimal to octal." << std::endl;
    std::cout << " -B binary to decimail." << std::endl;
    std::cout << " -b decimal to binary." << std::endl;
    std::cout << " -? print this usage." << std::endl;
    std::cout << " -x some usage samples." << std::endl;
    std::cout << std::endl;

    sample_usage(cmd, "101");
} // usage()

/**
 *  *�ɦL* �R�O�C�ѼơC�N�R�O�C�Ѽƥ��ƶɦL�b�ù��W�C
 *
 *  @param const int argc           �R�O�C�ѼƭӼ�
 *  @param const char *argv[]       �R�O�C�Ѽư}�C
 *  @return int
 *  @since  0.1.0
 **/
void args_dump(int argc, char* argv[]) {
    // �C�L�Ҧ��� *�R�O�C�Ѽ�*
    std::cout << "command line arguments: argv[i]" << std::endl;

    for (int i = 0; i < argc; i++) {
        std::cout
            << std::setfill(' ') << std::setw(3)
            << i << ": "
            << argv[i] << std::endl;
    }
}

/**
 *  �{���i�J�I�C
 *
 *  @param const int argc           �R�O�C�ѼƭӼ�
 *  @param const char *argv[]       �R�O�C�Ѽư}�C
 *  @return int
 *  @since  0.1.0
 **/
int main(int argc, char* argv[])
{
    std::string arg;
    std::string num;
    if (argc == 2)
    {
        arg = argv[1];
        if (arg == "-?")
        {
            usage(argv[0]);
        }
        else
        {
            error(argv[0], "Wrong number of or wrong arguments.");
        }
    }
    else if (argc == 3)
    {
        arg = argv[1];
        num = argv[2];
	if (arg == "-b")
        {
            dec2bin(num);
        }
        else if (arg == "-B")
        {
            bin2dec(num);
        }
		else if (arg == "-o")
        {
            dec2oct(num);
        }
        else if (arg == "-O")
        {
            oct2dec(num);
        }
        else if (arg == "-h")
        {
            dec2hex(num);
        }
        else if (arg == "-H")
        {
            hex2dec(num);
        }        
        else if (arg == "-x")
        {
            sample_usage(argv[0], num);
        }
    }
    else
    {
        error(argv[0], " Wrong number of or wrong arguments.");
    }


    // args_dump(argc, argv); // �p�G�Q�n�ˬd�{�������쪺
                              // �R�O�C�ѼơF�i�H�N�e����
                              // ���Ѯ���

    // �Цb�o�̩�W�A���{���X
    // �ϱo�sĶ�᪺�����ɦ欰�M sample.exe �@�P�C
    //
    // ²�满 *�{�� (sample.exe) �欰* ��`�U�C�W�h�G
    //
    //  1. sample -? : �I�s usage()
    //
    //  1. sample -b dec : �I�s dec2bin(dec)
    //
    //  1. sample -B bin : �I�s bin2dec(bin)
    //
    //  1. sample -h dec : �I�s dec2hex(dec)
    //
    //  1. sample -H hex : �I�s hex2dec(hex)
    //
    //  1. sample -o dec : �I�s dec2oct(dec)
    //
    //  1. sample -O oct : �I�s oct2dec(oct)
    //
    //  1. sample -x dec : �I�s sample_usage(dec)
    //
    //  ����d��
    //
    //  1. �i�H�b�R�O�C���� test.bat
    //
    //     C:\path_to\UI_Practice\9th\midterm> test.bat
    //
    //     �� sample.exe ������d��
    //
    //  1. �ΡA�b�R�O�C����G
    //
    //     C:\path_to\UI_Practice\9th\midterm> sample -?
    //
    //     �Ӭ� sample.exe ���Ϊk�F�A�ۦ���աC
    //
    //  ���յ{��
    //
    //  1. ���]�A���{���sĶ�� mywork.exe�A�b�R�O�C����G
    //
    //     C:\path_to\UI_Practice\9th\midterm> test.bat mywork
    //
    //     �� mywork.exe �����հ��浲�G
    //
    //  �W�ǵ{�� --- ��ۤv���{�����N��G
    //
    //  1. �P�B��ۤv�� GitHub �M�׸�
    //
    //  1. ���T�O�@�P���I��ɭ��A�ЦP�ɱN�o���ɮ� (midterm.cpp)
    //     �W�Ǥ@����Ʀ�ǲߥ��x�C
    //
    //  �@�~����
    //
    //  1. GitHub �������A�A�i�H�����s
    //
    //  1. �I������e�A�A�i�H�h���W���ɮר�Ʀ�ǲߥ��x
    //
    //  ��
    //    �@�����Q
} // main()
