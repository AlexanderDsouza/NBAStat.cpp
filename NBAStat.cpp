#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <sstream>
#include <map>
#include <unordered_map>


class Player {       // The class
public:             // Access specifier
    std::string team;
    std::string pos;
    int age;
    int gp;
    double mpg;
    double usage;
    double to;
    int fta;
    double ftp;
    int twopa;
    double twopp;
    int threepa;
    double threepp;
    double eFG;
    double TS;
    double ppg;
    double rpg;
    double apg;
    double spg;
    double bpg;
};



int main()
{
    
    std::ifstream in_file;
    //in_file.open("stat.txt"); playoffs
    in_file.open("regStats.txt");
    std::string mystring;
    Player temp;
    std::map<std::string, Player> database;


    if (in_file.is_open()) //is file open if so put all strings into word list 
    {
        while (in_file)
        {
            std::string Pname;
            std::string data;
            std::getline(in_file, mystring);
            std::istringstream iss(mystring);
            int i = 0;
            std::getline(iss, data, '\t');
            while (std::getline(iss, data, '\t')) 
            {
                i++;
                if (data == "\0")
                    continue;
                switch (i)
                {
                case 1:
                    Pname = data;
                    break;
                case 2:
                    temp.team = data;
                case 3:
                    temp.pos = data;
                    break;
                case 4:
                    temp.age = stoi(data);
                    break;
                case 5:
                    temp.gp = stoi(data);
                    break;
                case 6:
                    temp.mpg = stod(data);
                    break;
                case 7:
                    temp.usage = stod(data);
                    break;
                case 8:
                    temp.to = stod(data);
                    break;
                case 9:
                    temp.fta = stoi(data);
                    break;
                case 10:
                    temp.ftp = stod(data);
                    break;
                case 11:
                    temp.twopa = stoi(data);
                    break;
                case 12:
                    temp.twopp = stod(data);
                    break;
                case 13:
                    temp.threepa = stoi(data);
                    break;
                case 14:
                    temp.threepp = stod(data);
                    break;
                case 15:
                    temp.eFG = stod(data);
                    break;
                case 16:
                    temp.TS = stod(data);
                    break;
                case 17:
                    temp.ppg = stod(data);
                    break;
                case 18:
                    temp.rpg = stod(data);
                    break;
                case 19:
                    temp.apg = stod(data);
                    break;
                case 20:
                    temp.spg = stod(data);
                    break;
                case 21:
                    temp.bpg = stod(data);
                    break;
                default:
                        break;
      
                }
            }
            database[Pname] = temp;
        }
    }
    else
    {
        std::cout << "error could not find file\n";
        return -1;
    }

    std::string choice;
    while (1)
    {
        mystring = "";
        choice = "";
        std::cout << "1 for player list, 2 for specific player stats, 3 to quit\n\n";
        std::cin >> choice;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Clear the input buffer

        if (choice.size() > 1 || choice[0] > 51 || choice[0] < 48)
        {
            std::cout << "Invalid choice try again.\n\n";
            std::cin.clear();
            continue;
        }
        if (choice[0] == 49)
        {
            for (const auto& pair : database)
            {
                std::cout << pair.first << std::endl;
            }
        }
        if (choice[0] == 50)
        {
            std::cout << "Enter a player whos states you'd like to know.\n";
            std::getline(std::cin, mystring);
            auto it = database.find(mystring);
            if (it == database.end())
            {
                std::cout << "Player not found\n";
            }
            else
            {
                std::cout << "team: " << database[mystring].team << " position: " << database[mystring].pos << std::endl;
                std::cout << "age: " << database[mystring].age << std::endl;
                std::cout << "games played: " << database[mystring].gp << std::endl;
                std::cout << "minutes per game: " << database[mystring].mpg << std::endl;
                std::cout << "usage rate: " << database[mystring].usage << std::endl;
                std::cout << "turnovers: " << database[mystring].to << std::endl;
                std::cout << "free throw attempts: " << database[mystring].fta << std::endl;
                std::cout << "free throw percentage: " << database[mystring].ftp << std::endl;
                std::cout << "two-point attempts: " << database[mystring].twopa << std::endl;
                std::cout << "two-point percentage: " << database[mystring].twopp << std::endl;
                std::cout << "three-point attempts: " << database[mystring].threepa << std::endl;
                std::cout << "three-point percentage: " << database[mystring].threepp << std::endl;
                std::cout << "effective field goal percentage: " << database[mystring].eFG << std::endl;
                std::cout << "true shooting percentage: " << database[mystring].TS << std::endl;
                std::cout << "points per game: " << database[mystring].ppg << std::endl;
                std::cout << "rebounds per game: " << database[mystring].rpg << std::endl;
                std::cout << "assists per game: " << database[mystring].apg << std::endl;
                std::cout << "steals per game: " << database[mystring].spg << std::endl;
                std::cout << "blocks per game: " << database[mystring].bpg << std::endl << std::endl;

            }
            std::cin.clear();
        }
     
        if (choice[0] == 51)
            break;
    }
    


}