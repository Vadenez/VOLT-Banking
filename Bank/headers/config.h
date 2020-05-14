
class Account {

public:

    bool save;

    std::string username, pincode, debug = "Off";

    std::string n = "error on name", p = "error on pin", d = "error on debug";

    double b;

    double balance;

    //string bal = (std::to_string(balance));

    void file() {

        std::string cfgName = "cfg/acc/";

        cfgName += username;
        cfgName += ".cfg";
        if (save == 1) {

            std::ofstream outfile;

            outfile.open(cfgName);

            outfile << username << endl << pincode << endl << balance;

            outfile.close();
        }
        else {

            std::ifstream infile;

            infile.open(cfgName);

            infile >> n >> p >> b;

            username = n;
            pincode = p;
            balance = b;

            infile.close();

        }

    }

};
void error()
{
    PlaySound(TEXT("cfg/sound/winError.wav"), NULL, SND_FILENAME);
}
