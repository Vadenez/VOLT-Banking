#include <fstream>
class Account
{
public:
    bool save;
    std::string username, pin, debug = "Off";
    std::string n = "error on name", p = "error on pin", d = "error on debug";
    double b;
    double balance;

    //string bal = (std::to_string(balance));

    void iffy() {

        std::string cfgName = "cfg/acc/";

        cfgName += username;
        cfgName += ".cfg";
        if (save == 1) {

            std::ofstream outfile;

            outfile.open(cfgName);

            outfile << username << endl << pin << endl << balance << endl << debug;

            outfile.close();
        }
        else {

            std::ifstream infile;

            infile.open(cfgName);

            infile >> n >> p >> b >> d;

            username = n;
            pin = p;
            balance = b;
            debug = d;

            if (n == "error on name")
                cout << n << endl;
            else
                cout << p << endl;

            infile.close();

        }

    }

};
void error()
{
    PlaySound(TEXT("cfg/sound/winError.wav"), NULL, SND_FILENAME);
}
