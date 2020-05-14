
class Configs {

public:

    bool save;

    std::string username, pincode, debug = "Off";

    std::string n = "error on name", p = "error on pin", d = "error on debug";

    double b;

    double balance;

    //string bal = (std::to_string(balance));

    void accfile() {

        std::string accName = "cfg/acc/";

        accName += username;
        accName += ".cfg";
        if (save == 1) {

            std::ofstream outfile;

            outfile.open(accName);

            outfile << username << endl << pincode << endl << balance;

            outfile.close();
        }
        else {

            std::ifstream infile;

            infile.open(accName);

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
