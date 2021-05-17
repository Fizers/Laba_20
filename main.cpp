#include <memory>
#include "Generate.h"


using std::cout;
using std::cin;

int main()
{
    cout << "C++ generator:" << std::endl;
    cout << std::endl;
    Generate CDoublePlus(std::make_shared<GenerateCDoublePlus>());
    cout << CDoublePlus.generate() << std::endl;

    cout << "C# generator:" << std::endl;
    cout << std::endl;
    Generate CSharp(std::make_shared<GenerateCSharp>());
    cout << CSharp.generate() << std::endl;

    cout << "Java generator:" << std::endl;
    cout << std::endl;
    Generate Java(std::make_shared<GenerateJava>());
    cout << Java.generate() << std::endl;

    return 0;
}
