#include <iostream>
#include <string>

const int MAX_STATES = 500;
const int MAX_TRANSITIONS = 10;

int transCount[MAX_STATES] = {0};
char transSymbol[MAX_STATES][MAX_TRANSITIONS]; 
int transNext[MAX_STATES][MAX_TRANSITIONS];
bool accept[MAX_STATES] = {false};
int numStates = 0;
int startState = 0;

int addState(bool isAccept = false) 
    {
        accept[numStates] = isAccept;
        return numStates++;
    }

void addTransition(int from, char symbol, int to) 
    {
        transSymbol[from][transCount[from]] = symbol;
        transNext[from][transCount[from]] = to;
        transCount[from]++;
    }

int buildFSM(const std::string &regex, int &pos) 
    {
        int start = addState();
        int last = start;

        while (pos < (int)regex.size()) 
        {
            char c = regex[pos];

            if (c == '(') 
            {
                pos++;
                int subStart = buildFSM(regex, pos);
                int subEnd = numStates - 1;
                last = subStart;
            }
            else if (c == ')') 
            {
                pos++;
                return start;
            }
            else if (c == '|') 
            {
                pos++;
                int altStart = buildFSM(regex, pos);
                int newStart = addState();
                addTransition(newStart, 0, start);
                addTransition(newStart, 0, altStart);
                start = newStart;
                last = numStates - 1;
                return start;
            }
            else 
            {
                if (pos + 1 < (int)regex.size()) 
                {
                    char next = regex[pos + 1];
                    if (next == '*') 
                    {
                        int loopStart = addState();
                        addTransition(last, c, loopStart);
                        addTransition(loopStart, 0, last);
                        last = loopStart;
                        pos += 2;
                        continue;
                    }
                    if (next == '+') 
                    {
                        int loopStart = addState();
                        addTransition(last, c, loopStart);
                        addTransition(loopStart, c, loopStart);
                        last = loopStart;
                        pos += 2;
                        continue;
                    }
                    if (next == '?') 
                    {
                        int opt = addState();
                        addTransition(last, c, opt);
                        addTransition(last, 0, opt);
                        last = opt;
                        pos += 2;
                        continue;
                    }
                }

                int nextState = addState();
                addTransition(last, c, nextState);
                last = nextState;
                pos++;
            }
        }

        accept[last] = true;
        return start;
    }

void epsilonClosure(int states[], int &count) 
{
    for (int i = 0; i < count; i++) 
    {
        int state = states[i];
        for (int t = 0; t < transCount[state]; t++) 
        {
            if (transSymbol[state][t] == 0) 
            {
                bool exists = false;
                for (int k = 0; k < count; k++)
                    if (states[k] == transNext[state][t]) exists = true;
                if (!exists) states[count++] = transNext[state][t];
            }
        }
    }
}

bool match(const std::string &input) 
{
    int current[MAX_STATES], next[MAX_STATES];
    int curCount = 1;
    current[0] = startState;
    epsilonClosure(current, curCount);

    for (size_t i = 0; i < input.size(); i++) 
    {
        int nextCount = 0;
        for (int j = 0; j < curCount; j++) 
        {
            int state = current[j];
            for (int t = 0; t < transCount[state]; t++) 
            {
                if (transSymbol[state][t] == input[i] || transSymbol[state][t] == '.') 
                {
                    next[nextCount++] = transNext[state][t];
                }
            }
        }
        curCount = nextCount;
        for (int k = 0; k < curCount; k++) current[k] = next[k];
        epsilonClosure(current, curCount);
        if (curCount == 0) return false;
    }

    for (int j = 0; j < curCount; j++)
        if (accept[current[j]]) return true;
    return false;
}

int main() {
    std::string regex = "(a|b)*abb";
    int pos = 0;
    startState = buildFSM(regex, pos);

    std::string tests[] = {"abb", "aabb", "babb", "ab", "aab"};
    for (int i = 0; i < 5; i++) {
        std::cout << tests[i] << " -> " << (match(tests[i]) ? "MATCH" : "NO MATCH") << "\n";
    }
}
