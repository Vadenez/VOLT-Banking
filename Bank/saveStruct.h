#include <fstream>
class Account
{
public:
    bool save;
    std::string username, pin;
    int balance;

    //string bal = (std::to_string(balance));

    void iffy() {

        std::string cfgName = "cfg/acc/";

        cfgName += username;
        cfgName += ".cfg";

        if (save == 1) {

            std::ofstream outfile;
            
            outfile.open(cfgName);

            outfile << "Username: " << username << "\nPin Code: " << pin << "\nCurrent Balance: " << balance;

            outfile.close();

        }
        else {

            std::ifstream infile;

            infile.open(cfgName);

            infile >> username >> pin >> balance;

            infile.close();

        }
            
    }
    
};
