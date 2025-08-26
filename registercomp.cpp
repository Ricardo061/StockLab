/* =======================================================================================================
 *
 * Arquivo Classe .cpp
 * Programa para controle de estoque.
 * Author: Joao Ricardo Chaves
 * Date: 30/05/25
 * 
 * =======================================================================================================
 */ 

// ============================================
// --- Libraries ---
#include "registercomp.hpp"

// ============================================
// --- Functions ---

// ============================================
// --- Constructor ---
Registercomp::Registercomp()
{

}// end constructor

// ============================================
// --- SetID ---
void Registercomp::SetID(int ID)
{
        _ID = ID;               
}// end SetID

// ============================================
// --- getID ---
int Registercomp::getID() const
{
        return _ID;
}// end getID

// ============================================
// --- SetQuantidade ---
void Registercomp::SetQuantidade(int QTD)
{
        _Qtd = QTD;
}// end SetQuantidade

// ============================================
// --- getQuantidade ---
int Registercomp::getQuantidade() const
{
       return _Qtd; 
}// end getQuantidade

// ============================================
// --- SetPrice ---
void Registercomp::SetPrice(double Price)
{
        _Price = Price;
}// end SetPrice

// ============================================
// --- getPrice ---
double Registercomp::getPrice() const
{
        return _Price;
}// end GetPrice

// ============================================
// --- SetName ---
void Registercomp::SetName(const string &Name)
{
        _Name = Name;
}// end SetName

// ============================================
// --- getName ---
string Registercomp::getName() const
{
        return _Name;
}// end getName

// ============================================
// --- SetCategory ---
void Registercomp::SetCategory(const string &Category)
{
        _Category = Category;
}// end SetCategory

// ============================================
// --- getCategory ---
string Registercomp::getCategory() const
{
        return _Category;
}// end GetCategory

// ============================================
// --- SetValor ---
void Registercomp::SetValue(double Value)
{
        _Value = Value;
}// end SetValue

// ============================================
// --- getValue ---
double Registercomp::getValue() const
{
        return getPrice() * static_cast<double>(getQuantidade());
}// end getValue

// ============================================
// --- SetDescription ---
void Registercomp::SetDescription(const string &Description)
{
        _description = Description;
}// end SetDescription

// ============================================
// --- GetDescription ---
string Registercomp::getDescription() const
{
        return _description;
}// end 

// ============================================
// --- RegisterComponent ---
void Registercomp::RegisterComponent() const
{

        ofstream CompArq("stockFile",ios::app);
        if(!CompArq)
        {
                cerr << RED << "Falha na criacao de Arquivo!"<<endl;
                return;
        }//end if


        CompArq << getID()          << ','
                << getName()        << ','
                << getCategory()    << ','
                << getQuantidade()  << ','
                << getPrice()       << ','
                << getDescription() << ','
                << getValue()       << endl;

        CompArq.close();
}// end RegisterComponent

// ============================================
// --- LoadStock ---
void Registercomp::LoadStock() const
{
        ifstream stockRead("stockFile",ios::in);
        if(!stockRead)
        {
                cerr << RED << " Falha na leitura do Arquivo!" << endl;
                return;
        }//end if

        string line;
        PrintCharline();
        cout << "\n|"
             << setw(12) << "ID" << " |"
             << setw(16) << "NAME" << " |"
             << setw(16) << "CATEGORY" << " |"
             << setw(12) << "AMOUNT" << " |"
             << setw(9) << "PRICE" << " |"
             << setw(14) << "DESCRIPTION" << " |"
             << setw(11) << "SUB-VALUE" << " |";
        cout << "\n";
        PrintCharline();
        cout << "\n";

        double totalValue = 0.0;
        while(getline(stockRead,line))
        {
                stringstream ss(line);
                string ID, name, category, amount, price, description, subvalue;

                getline(ss,ID,',');
                getline(ss,name,',');
                getline(ss,category,',');
                getline(ss,amount,',');
                getline(ss,price,',');
                getline(ss,description,',');
                getline(ss,subvalue,',');

                cout << "|"
                << setw(12) << ID << " |"
                << setw(16) << name << " |"
                << setw(16) << category << " |"
                << setw(12) << amount << " |"
                << setw(9) << price << " |"
                << setw(14) << description << " |"
                << setw(11) << subvalue << " |\n";

                totalValue += stod(subvalue);

        }// end while
        PrintCharline();
        cout << "\n"
        << setw(12) << " " << "  "
        << setw(16) << " " << "  "
        << setw(16) << " " << "  "
        << setw(12) << " " << "  "
        << setw(10)  << " " << " |"
        << setw(14) << "TOTAL STOCK" << " |"
        << setw(11) << fixed << setprecision(2) << totalValue << " |\n";

        cout << string(13,' ') << " ";
        cout << string(17,' ') << " ";
        cout << string(17,' ') << " ";
        cout << string(13,' ') << " ";
        cout << string(11,' ') << "+";
        cout << string(15,'-') << "+";
        cout << string(12,'-') << "+";

        stockRead.close();
}// end LoadStock

// ================================
// --- PrintChar ---
void Registercomp::PrintCharline() const
{
        cout << "+";
        cout << string(13,'-') << "+";
        cout << string(17,'-') << "+";
        cout << string(17,'-') << "+";
        cout << string(13,'-') << "+";
        cout << string(10,'-') << "+";
        cout << string(15,'-') << "+";
        cout << string(12,'-') << "+";
}// end PrintChar

// ================================
// --- RemoveProduct ---
void Registercomp::RemoveProduct() const
{
        string TargetName;
        cout << "Enter the Name: ";
        cin  >> TargetName;
        
        ifstream InputFile("stockFile");
        ofstream OutputFile("temp.txt");

        if(!InputFile || !OutputFile)
        {
                cerr << RED << "Error opening File!" << endl;
                return;
        }//end if

        string line;
        bool found = false;

        while(getline(InputFile,line))
        {
                stringstream ss(line);
                string ID,Name;
                getline(ss,ID,',');
                getline(ss,Name,',');

                if(Name != TargetName)
                        OutputFile << line << "\n";
                else
                {
                        found = true;
                        cout << "\n";
                        cout << GREEN << "Product " << TargetName 
                                      << " Removed!" << RESET << endl;
                }// end else
        }//end while

        InputFile.close();
        OutputFile.close();

        remove("stockFile");
        rename("temp.txt","stockFile");

        if(!found)
                cout << RED << "Product " << TargetName << " not Found" << RESET << endl;
}// end RemoveProduct

// ================================
// --- Modify Product ---
void Registercomp::ModifyProduct() const
{
        string TargetName;
        cout << "Enter the Name: ";
        cin  >> TargetName;
        
        ifstream InputFile("stockFile");
        ofstream OutputFile("temp.txt");

        if(!InputFile || !OutputFile)
        {
                cerr << RED << "Error opening File!" << endl;
                return;
        }//end if

        string line;
        bool found = false;

        while(getline(InputFile,line))
        {
                stringstream ss(line);
                string ID,Name;
                getline(ss,ID,',');
                getline(ss,Name,',');

                if(Name != TargetName)
                        OutputFile << line << "\n";
                else
                {
                        found = true;
                        cout << "\nEnter new Name: ";
                        string newName;
                        cin.ignore();
                        getline(cin, newName);

                        cout << "Enter new Category: ";
                        string newCategory;
                        getline(cin, newCategory);

                        cout << "Enter new Quantity: ";
                        int newQuantity;
                        cin >> newQuantity;

                        cout << "Enter new Price: ";
                        double newPrice;
                        cin >> newPrice;

                        cout << "Enter new Description: ";
                        string newDescription;
                        cin.ignore();
                        getline(cin, newDescription);

                        double subValue = newQuantity * newPrice;

                        OutputFile << ID << ','
                                   << newName << ','
                                   << newCategory << ','
                                   << newQuantity << ','
                                   << newPrice << ','
                                   << newDescription << ','
                                   << subValue << '\n';

                        cout << GREEN << "Product " << TargetName << " modified.\n" << RESET;
                }//end else

        }// end while

        InputFile.close();
        OutputFile.close();

        remove("stockFile");
        rename("temp.txt","stockFile");

        if(!found)
                cout << RED << "Product " << TargetName << " not Found" << RESET << endl;
}// end ModifyProduct

// ================================
// --- End Of File ---

//=======================================================================================================
//
//     ██╗██████╗     ███████╗██╗     ███████╗ ██████╗████████╗██████╗  ██████╗ ███╗   ██╗██╗ ██████╗
//     ██║██╔══██╗    ██╔════╝██║     ██╔════╝██╔════╝╚══██╔══╝██╔══██╗██╔═══██╗████╗  ██║██║██╔════╝
//     ██║██████╔╝    █████╗  ██║     █████╗  ██║        ██║   ██████╔╝██║   ██║██╔██╗ ██║██║██║     
//██   ██║██╔══██╗    ██╔══╝  ██║     ██╔══╝  ██║        ██║   ██╔══██╗██║   ██║██║╚██╗██║██║██║     
//╚█████╔╝██║  ██║    ███████╗███████╗███████╗╚██████╗   ██║   ██║  ██║╚██████╔╝██║ ╚████║██║╚██████╗
// ╚════╝ ╚═╝  ╚═╝    ╚══════╝╚══════╝╚══════╝ ╚═════╝   ╚═╝   ╚═╝  ╚═╝ ╚═════╝ ╚═╝  ╚═══╝╚═╝ ╚═════╝
//                                                                                                 
//=======================================================================================================