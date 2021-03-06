#include <BigNumbers/BigNumbers.h>
#include <iostream>
#include <memory>


#if 0 
Sum = c590e57ee64fcef321395bba088ca0a867e1e85a1ea77478f8783e6a6cf8f3e582bff83cb2d7d9fd549fcbb40dea22ac140351007030059500bdca81413600e9
A = c590e57ee64fced18aff6e2f0c6ac05625b1e94f394f42470cae14d12cadea4f5ab6b9d77225fe3b4903825966c78752ae51b6a0a2caca555fd0ffcbd9704b01
B = 219639ed8afc21e052422fff0ae5583231ebca2999404b099628093e6540b1dbc20b9c495aa7229b5965b19a5fcd653b3fa0eccab567c5b5e8
#endif

int main(int argc, char**argv)
{
    BigNumber val;

    std::string SumA("");
    std::string AVal = "c590e57ee64fced18aff6e2f0c6ac05625b1e94f394f42470cae14d12cadea4f5ab6b9d77225fe3b4903825966c78752ae51b6a0a2caca555fd0ffcbd9704b01";
    std::string BVal("219639ed8afc21e052422fff0ae5583231ebca2999404b099628093e6540b1dbc20b9c495aa7229b5965b19a5fcd653b3fa0eccab567c5b5e8");

    BigNumber BNValA, BNValB;
    BNValA.FromHex(AVal);
    BNValB.FromHex(BVal);


    std::cout << BNValA.ToHex() << "\n" << BNValB.ToHex() << std::endl;

    BigNumber Sum = BNValA + BNValB;
    std::cout << Sum.ToHex() << std::endl;

    {
        const BigNumber bn_256 = GenerateRand(256);
        const BigNumber bn_512 = GenerateRand(512);
        const BigNumber bn_1024 = GenerateRand(1024);
        const BigNumber bn_2048 = GenerateRand(2048);

        std::cout << "256-bit dec\n" << bn_256.ToDec() << "\n"
            << "512-bit dec\n" << bn_512.ToDec() << "\n"
            << "1024-bit dec\n" << bn_1024.ToDec() << "\n"
            << "2048-bit dec\n" << bn_2048.ToDec()
            << std::endl;
    }
    {
        const BigNumber bn_256 = GenerateRand(256);
        const BigNumber bn_512 = GenerateRand(512);
        const BigNumber bn_1024 = GenerateRand(1024);
        const BigNumber bn_2048 = GenerateRand(2048);

        std::cout << "256-bit hex\n" << bn_256.ToHex()  << "\n"
            << "512-bit hex\n" << bn_512.ToHex() << "\n"
            << "1024-bit hex\n" << bn_1024.ToHex() << "\n"
            << "2048-bit hex\n" << bn_2048.ToHex()
            << std::endl;
    }
    /// Comment out this code because it discover some design issue : the code can compile only in C++ and not compile in wasm
    //BIGNUM_RETURN_TYPE SubRes = subFromHex(BNRandomHex (2048).get(), BNRandomHex (2048).get () );
    //std::cout << "Result of 2048-bit subtraction " << SubRes.get() << std::endl ;


    //std::string StrSmallNumberMin ("-5");
    //std::string strSmallNumberMax ("5");

    std::string StrSmallNumberMin("1000");
    std::string strSmallNumberMax("100000000000000000000");

    BigNumber minVal, maxVal;
    minVal.FromDec(StrSmallNumberMin);
    maxVal.FromDec(strSmallNumberMax);

    for (int i = 0; i < 10000; ++i)
    {
        BigNumber randRange = GenerateRandRange(minVal, maxVal);
        //std::cout << randRange.ToDec () << std::endl ; 


        // check 
        if (randRange < minVal || randRange > maxVal)
        {
            std::cout << "success on random range" << std::endl;
        }
    }


    BigNumber seedval;
    seedval.generateRandHex(1024);
    BigNumber seededRanVal;
    seededRanVal.generateRandHexWithSeed(seededRanVal.ToHex(), 1024);

    std::cout << " Random number generated with seed " << "\n"
        << seededRanVal.ToHex() << std::endl;
    ++seededRanVal;
    std::cout << " pre- Incremented " << seededRanVal.ToHex() << std::endl;
    seededRanVal++;
    std::cout << " post - Incremented " << seededRanVal.ToHex() << std::endl;

    --seededRanVal;
    std::cout << " pre - decremented " << seededRanVal.ToHex() << std::endl;

    seededRanVal--;
    std::cout << " post - decremented " << seededRanVal.ToHex() << std::endl;


    std::cout << "Initialise with the seed: The quick brown fox jumped over the lazy dog" << std::endl;


    // A SHA256 of "The quick brown fox jumped over the lazy dog";
    std::string seedVal = "8d18fbf476ed981c3a21662c6244abaf4e1f976f6e2421690ea8daf5093a5740";
    BigNumber seed;
    seed.FromHex(seedVal.c_str());
    BigNumber seedVal1;
    seedVal1.generateRandHexWithSeed(seedVal, 512);
    BigNumber seedVal2;
    seedVal2.generateRandHexWithSeed(seedVal, 512);
    std::cout << seedVal1.ToHex() << std::endl;
    std::cout << seedVal2.ToHex() << std::endl;

std::cout << "\n======================1 <<4================================\n";
    BigNumber bnValue; 
    bnValue.FromDec("1");
    BigNumber res = bnValue << 4;
    std::cout << "1 << 4 :" << res.ToDec () <<  std::endl;
std::cout << "\n======================================================\n";

std::cout << "\n======================1 << 65536================================\n";
        bnValue.FromDec("1");
        res = bnValue << 65536;
        std::cout << "1 <<" << 65536 << " :" << res.ToDec () <<  std::endl;
	//sleep(1);
std::cout << "\n======================================================\n";
std::cout << "\n======================(1 << 65536) >> 65536================================\n";
       res = res >> 65536;
        std::cout << "(1 << 65536) >>" << 65536 << " :" << res.ToDec () <<  std::endl;
std::cout << "\n======================================================\n";

std::cout << "\n======================1 << 65536================================\n";
    BigNumber bnValueShift; 
        bnValue.FromDec("1");
        bnValueShift.FromDec("65536");
        res = bnValue << bnValueShift;
        std::cout << "1 <<" << 65536 << " :" << res.ToDec () <<  std::endl;
	//sleep(1);
std::cout << "\n======================================================\n";

std::cout << "\n======================(1 << 65536) >> 65536================================\n";
       res = res >> bnValueShift;
        std::cout << "(1 << 65536) >>" << 65536 << " :" << res.ToDec () <<  std::endl;
std::cout << "\n======================================================\n";

    std::string  AvalMul("1000");
    std::string  BValMul ("100000000000000000000");

    BigNumber aValMul, bValMul; 
    aValMul.FromDec(AvalMul);
    bValMul.FromDec(BValMul);

    BigNumber resMul = aValMul * bValMul;
    std::cout << aValMul.ToDec() << " * " << bValMul.ToDec() << " = " << resMul.ToDec() << std::endl;

    BigNumber resDiv = bValMul/aValMul;
    std::cout << bValMul.ToDec() << " / " << aValMul.ToDec() << " = " << resDiv.ToDec() << std::endl;

    resDiv = aValMul/bValMul;
    std::cout << aValMul.ToDec() << " / " << bValMul.ToDec() << " = " << resDiv.ToDec() << std::endl;

    return 0;
}

