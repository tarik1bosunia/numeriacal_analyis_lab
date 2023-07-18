#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>

int main() {
    std::string variableName, variableValue;

    std::cout << "Enter a variable name: ";
    std::cin >> variableName;

    std::cout << "Enter the value for " << variableName << ": ";
    std::cin.ignore();  // Ignore the newline character in the input stream
    std::getline(std::cin, variableValue);

    std::ofstream outputFile("generated_code.cpp");
    outputFile << "#include <iostream>\n";
    outputFile << "int main() {\n";
    outputFile << "    std::string " << variableName << " = \"" << variableValue << "\";\n";
    outputFile << "    std::cout << \"Variable name: \" << " << variableName << " << std::endl;\n";
    outputFile << "    return 0;\n";
    outputFile << "}\n";
    outputFile.close();

    //  unix
    // std::string compileCommand = "g++ -o generated_code generated_code.cpp";
    // std::string executeCommand = "./generated_code";

    // windows
    std::string compileCommand = "g++ -o generated_code.exe generated_code.cpp";
    std::string executeCommand = "generated_code.exe";

    std::system(compileCommand.c_str());
    std::system(executeCommand.c_str());

    return 0;
}
