#pragma once
#include "compiledCode.hpp"

class ScriptSerializer {
public:
    static void compiledToHumanReadable(const CompiledCodeData& code, std::ostream& output);
    static void compiledToBinary(const CompiledCodeData& code, std::ostream& output);
    static CompiledCodeData binaryToCompiled(std::istream& input);

    static void compiledToBinaryCompressed(const CompiledCodeData& code, std::ostream& output);
    static CompiledCodeData binaryToCompiledCompressed(std::istream& input);
    static CompiledCodeData binaryToCompiledCompressed(std::string_view input);




private:
    static void instructionToBinary(const CompiledCodeData& code, const ScriptInstruction& instruction, std::ostream& output);
    static void instructionsToBinary(const CompiledCodeData& code, const std::vector<ScriptInstruction>& instructions,
                                     std::ostream& output);

    static ScriptInstruction binaryToInstruction(const CompiledCodeData& code, std::istream& input);
    static std::vector<ScriptInstruction> binaryToInstructions(const CompiledCodeData& code, std::istream& input);;

    static void writeConstants(const CompiledCodeData& code, std::ostream& output);
    static void readConstants(CompiledCodeData& code, std::istream& input);



    static std::vector<char> compressData(const std::vector<char>& data);
    static std::vector<char> compressDataDictionary(const std::vector<char>& data, const std::vector<char>& dictionary);


    static std::vector<char> decompressData(std::string_view data);
    static std::vector<char> decompressDataDictionary(const std::vector<char>& data, const std::vector<char>& dictionary);
};