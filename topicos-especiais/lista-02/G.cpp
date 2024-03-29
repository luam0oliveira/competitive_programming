#include <iostream>
#include <set>
#include <string>
#include <sstream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

class Equipe
{
public:
    int id, tempo, questao;
    map<int,pair<char, int>> questoes;
    
    Equipe() {}
    Equipe(int id)
    {
        this->id = id;
        this->tempo = 0;
        this->questao = 0;
    }

    void addQuestao(int questao, int tempo, char result)
    {
        auto it = this->questoes.find(questao);
        
        if (it != this->questoes.end() && this->questoes[questao].first == 'C')
            return;
        
        if (result == 'C')
        {
            if (it == this->questoes.end())
            {
                this->questoes[questao] = {'C',0};
                this->questao += 1;
                this->tempo += tempo;
                return;
            }
            
            this->tempo += tempo;
            this->tempo += this->questoes[questao].second * 20;
            this->questoes[questao].first = 'C';
            this->questao+=1;
            return;
        }
        else
        if (result == 'I')
        {
            if (it == this->questoes.end())
                this->questoes[questao] = {'I', 1};
            else
                this->questoes[questao] = {'I', this->questoes[questao].second + 1};
        }
    }
    
    bool operator < (const Equipe& other)
    {
        
        if (this->questao != other.questao)
        {
            return this->questao > other.questao;
        }
        
        if (this->tempo != other.tempo)
        {
            return this->tempo < other.tempo;
        }
        
        return this->id < other.id;
        
    }
};

int main()
{
    int cases;

    cin >> cases;
    string line;
    int equipe, questao, tempo;
    char operacao;
    istringstream trans;

    cin.ignore();
    cin.ignore();
    
    while (cases--)
    {
        map <int, Equipe> equipes;
        while (getline(cin, line) && line.length() != 0)
        {

            trans = istringstream(line);

            trans >> equipe >> questao >> tempo >> operacao;
            
            auto it = equipes.find(equipe);
            
            if (it == equipes.end())
            {
                Equipe ep(equipe);
                equipes[equipe] = ep;
            }
            equipes[equipe].addQuestao(questao, tempo, operacao);
        }
        
        vector <Equipe> placar;
        
        for ( auto it = equipes.begin(); it != equipes.end(); it++)
            placar.push_back(it->second);
    
        sort(placar.begin(), placar.end());
        for (int i = 0; i < placar.size(); i++)
        {
            cout << placar[i].id << " " << placar[i].questao << " " << placar[i].tempo << "\n";
        }
        
        if (cases)
            cout << endl;
    }
    return 0;
}
