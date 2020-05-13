//creates global strings


class Account
{
public:
    Account();
   /// std::string Username = user;
    ~Account();
private:

};

Account::Account()
{
}

Account::~Account()
{
}
#include <fstream>
float data1 = 1.7f;
int data2 = 55;
bool data3 = true;
void save(const std::string _Filepath)
{
    std::ofstream outfile;
    outfile.open(_Filepath);
    outfile << data1 << " " << data2 << " " << data3;
    outfile.close();
}
void load(const std::string _Filepath)
{
    std::ifstream infile;
    infile.open(_Filepath);
    infile >> data1 >> data2 >> data3;
    infile.close();
}