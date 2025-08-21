#include <iostream>
#include <string>

const int MAX = 100;

int main() 
    {
        std::string inputAlphabet[MAX], outputAlphabet[MAX], states[MAX];
        std::string nextState[MAX][MAX], output[MAX][MAX];
        int numInputs = 0, numOutputs = 0, numStates = 0;

        std::string line;

        std::getline(std::cin, line);
        int pos = 0;
        while (pos < (int)line.size()) 
            {
                while (pos < (int)line.size() && line[pos] == ' ') 
                    {
                        pos++;
                    }
                if (pos >= (int)line.size()) 
                    {
                        break;
                    }
                int end = pos;
                while (end < (int)line.size() && line[end] != ' ') 
                    {
                        end++;
                    }
                inputAlphabet[numInputs++] = line.substr(pos, end - pos);
                pos = end;
            }

        std::getline(std::cin, line);
        pos = 0;
        while (pos < (int)line.size()) 
            {
                while (pos < (int)line.size() && line[pos] == ' ') 
                    {
                        pos++;
                    }
                if (pos >= (int)line.size()) 
                    {
                        break;
                    }
                int end = pos;
                while (end < (int)line.size() && line[end] != ' ') 
                    {
                        end++;
                    }
                outputAlphabet[numOutputs++] = line.substr(pos, end - pos);
                pos = end;
            }

        std::getline(std::cin, line);
        pos = 0;
        while (pos < (int)line.size()) 
            {
                while (pos < (int)line.size() && line[pos] == ' ') 
                    {
                        pos++;
                    }
                if (pos >= (int)line.size()) 
                    {
                        break;
                    }
                int end = pos;
                while (end < (int)line.size() && line[end] != ' ') 
                    {
                        end++;
                    }
                states[numStates++] = line.substr(pos, end - pos);
                pos = end;
            }

        for (int i = 0; i < numStates; i++) 
            {
                std::getline(std::cin, line);
                if (line.empty()) 
                    { 
                        i--; continue; 
                    }
                int j = 0;
                pos = 0;
                while (pos < (int)line.size() && j < numInputs) 
                    {
                        while (pos < (int)line.size() && line[pos] == ' ') 
                            {
                                pos++;
                            }
                        if (pos >= (int)line.size()) 
                            {
                                break;
                            }
                        int end = pos;
                        while (end < (int)line.size() && line[end] != ' ' && line[end] != '|') 
                            {
                                end++;
                            }
                        std::string token = line.substr(pos, end - pos);
                        int comma = -1;
                        for (int k = 0; k < (int)token.size(); k++) 
                            {
                                if (token[k] == ',') { comma = k; break; }
                            }
                        if (comma != -1) 
                            {
                                nextState[i][j] = token.substr(0, comma);
                                output[i][j] = token.substr(comma + 1);
                            }
                        pos = end;
                        if (pos < (int)line.size() && line[pos] == '|') pos++;
                        j++;
                    }
            }

        std::string currentState = states[0];
        std::cout << "Start at " << currentState << "\nOutputs: ";

        while (std::cin >> line) 
            {
                if (line == "#") 
                    {
                        break;
                    }
                int sIndex = -1, inIndex = -1;
                for (int i = 0; i < numStates; i++) 
                    {
                        if (states[i] == currentState) 
                            {
                                sIndex = i;
                            }
                    }
                for (int j = 0; j < numInputs; j++) 
                    {
                        if (inputAlphabet[j] == line) 
                            {
                                inIndex = j;
                            }
                    }
                if (sIndex == -1 || inIndex == -1 || nextState[sIndex][inIndex] == "") 
                    {
                        std::cout << "\nError: invalid input symbol or transition.\n";
                        return 1;
                    }
                std::cout << output[sIndex][inIndex] << " ";
                currentState = nextState[sIndex][inIndex];
            }

        std::cout << "\nFinal state: " << currentState << std::endl;
        return 0;
    }
