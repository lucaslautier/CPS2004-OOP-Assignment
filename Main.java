// import java.io.BufferedOutputStream;
// import java.io.BufferedReader;
// import java.io.BufferedWriter;
// import java.io.InputStreamReader;
// import java.io.OutputStream;
// import java.io.OutputStreamWriter;
// import java.nio.file.Files;

import java.util.*;
import java.nio.file.*;
import java.io.*;
import static java.nio.file.StandardOpenOption.*;
import java.nio.charset.*;
import java.util.stream.*;

public class Main{

    public static void main(String[] args) throws FileNotFoundException, IOException
    {
        clearFile("crypto.txt");
        fillCryptos();
        User user = new User();
        Currencies currCrypto = new Currencies();
        Scanner s = new Scanner(System.in);
        int option = 0;
        boolean exit = false;

        do{
        //CHANGE MENU TO:
        //1. CREATE 2.BUY 3.SELL 4.EXIT
        //BUY & SELL - HAVE LOGIN THEN CALL METHOD
        System.out.println("Enter what option you would like to choose");
        System.out.println("1. Create Account");
        System.out.println("2. Login");
        System.out.println("3. Exit");
        option = s.nextInt();

        switch (option){
            case 1:
                createAccount();
                break;
            case 2:
                long accountNo = login(user);
                System.out.println(accountNo);
                buyCrypto(currCrypto, user, accountNo);
                break;
            
            case 3:
                exit = true;
                s.close();
                break;

            case 5:
                // buyCrypto(currCrypto, user);
            
            case 99:
                admin();
                break;
        }
        
        }while(option != 3);
    }

    public static long login(User tmpUser)
    {
        long _acc = 1000;
        Scanner s = new Scanner(System.in);
            String filename = "account.txt";
            try
            {
                Path path = Paths.get(filename.toString());
                InputStream input = Files.newInputStream(path);
                BufferedReader reader = new BufferedReader(new InputStreamReader(input));

                System.out.println("LOGIN");
                System.out.println("Enter username: ");
                String username = s.nextLine();
                System.out.println(("Enter password: "));
                String password = s.nextLine();
                String _temp = null;
                String _user = " ";
                String _pass = " ";
                // String _user = tmpUser.getUser();
                // String _pass = tmpUser.getPass();
                // _acc = tmpUser.getAccNo();
    
                boolean found = false;
                while((_temp = reader.readLine()) != null)
                {
                    String[] account = _temp.split(",");
                    _user = account[1];
                    _pass = account[2];
                    
                   
                    
                    if(_user.equals(username) && _pass.equals(password)){
                        found = true;
                        _acc = Long.parseLong(account[0]) ;
                    }
                }
                if(found == true){
                    System.out.println("Login Successful");

                }
                else{
                    System.out.println("Credentials entered did not match or account is not verified by administrator.");
                }
                
                System.out.println("Press any key to continue...");
                String cont = s.nextLine();
                
            }catch(Exception ex){
                System.out.print(ex.getMessage());
                s.close();
            }

            
            return _acc;
            
    }

    public static User createAccount()
    {
        User tmpUser = new User();
        Scanner s = new Scanner(System.in);
        String filename = "waiting.txt";
        String file = "account.txt";
        //System.out.println(new File("account.txt").getAbsoluteFile());
        
            try{
                // ALL NEW ACCOUNTS SAVED IN "waiting.txt"
                // BOTH TEXT FILES USED ANYWAY (for account number)

                // setup for "waiting.txt"
                Path path = Paths.get(filename.toString()); 
                OutputStream output = new BufferedOutputStream(Files.newOutputStream(path, APPEND));
                BufferedWriter writer = new BufferedWriter(new OutputStreamWriter(output));
                Scanner sc = new Scanner(path);

                //setup for "account.txt"
                Path accPath = Paths.get(file.toString());
                BufferedReader acnt = new BufferedReader(new FileReader(accPath.toString()));
                Scanner scA = new Scanner(accPath);
                
                int accNo = 0;
                
                // checks if "account.txt" is empty
                //yes - this is the first account, start counting from 0
                if(acnt.readLine() == null){
                    while(sc.hasNextLine())
                    {
                        sc.nextLine();
                        accNo++;
                    }

                //no - other accounts have been made, so use the account number after the one in "account.txt"
                }else{
                    while(scA.hasNextLine())
                    {
                        scA.nextLine();
                        accNo++;
                    }
                }

                tmpUser.setAccNo(accNo);
                sc.close();
                scA.close();

                
                //GETTING USER DETAILS, SAVING IN set() methods
                System.out.println("CREATE ACCOUNT");
                System.out.println("Enter username: ");
                String username = s.nextLine();
                tmpUser.setUser(username);
                System.out.println(("Enter password: "));
                String password = s.nextLine();
                tmpUser.setPass(password);
                System.out.println(("Enter money: "));
                double startingInvestment = s.nextDouble();
                tmpUser.setMoney(startingInvestment);

                //SAVES USER DETAILS IN FILE
                writer.write(tmpUser.getAccNo()+","+tmpUser.getUser() + "," + tmpUser.getPass()+','+tmpUser.getMoney());
                writer.newLine();
                System.out.println("Your account has been sent to admin for approval");

                writer.close();
                output.close();

                
                System.out.println("Press any key to continue...");
                String cont = s.nextLine();
                //new Main();

            }catch(Exception ex){
                System.out.println(ex.getMessage());
                s.close();
            }
            
        
        return tmpUser;
    }

    public static void clearFile(String file) throws IOException{
        PrintWriter writer = new PrintWriter(file);
        writer.print("");
        writer.close();
    }

    //CRYPTOCURRENCY METHODS

    //LOAD CRYPTOS INTO FILE
    public static void fillCryptos(){
        Currencies currCrypto = new Currencies();
        String cryptoFile = "crypto.txt";
        
        try{
            Path path = Paths.get(cryptoFile.toString()); 
            OutputStream output = new BufferedOutputStream(Files.newOutputStream(path, APPEND));
            BufferedWriter writer = new BufferedWriter(new OutputStreamWriter(output));
            
            // FileWriter writer = new FileWriter(cryptoFile);
            currCrypto.setCrypto("BTC");
            currCrypto.setValue("504.98");
            writer.write(currCrypto.getCrypto()+","+currCrypto.getValue());
            writer.newLine();
            
            currCrypto.setCrypto("SOL");
            writer.write(currCrypto.getCrypto()+","+currCrypto.getValue());
            writer.newLine();

            currCrypto.setCrypto("ETH");
            currCrypto.setValue("250.17");
            writer.write(currCrypto.getCrypto()+","+currCrypto.getValue());
            writer.newLine();

            currCrypto.setCrypto("XRP");
            currCrypto.setValue("2.25");
            writer.write(currCrypto.getCrypto()+","+currCrypto.getValue());
            writer.newLine();

            currCrypto.setCrypto("DOT");
            currCrypto.setValue("15.67");
            writer.write(currCrypto.getCrypto()+","+currCrypto.getValue());
            writer.newLine();

            writer.close();
        }catch(Exception ex){
            System.out.println(ex.getMessage());
            ex.printStackTrace();
        }

    }


    //BUY CRYPTO
    public static void buyCrypto(Currencies currCrypto, User user, long pAccNo){


        Scanner s = new Scanner(System.in);
        String cryptoFile = "crypto.txt";
        String portfolioFile = "portfolio.txt";
        
        try{
            Path path = Paths.get(cryptoFile.toString());
            InputStream input = Files.newInputStream(path);
            BufferedReader reader = new BufferedReader(new InputStreamReader(input));


            Path portpath = Paths.get(portfolioFile.toString()); 
            OutputStream output = new BufferedOutputStream(Files.newOutputStream(portpath, APPEND));
            BufferedWriter writer = new BufferedWriter(new OutputStreamWriter(output));
            Scanner sc = new Scanner(portpath);

            System.out.println("What crypto would you like to buy: ");
            String crypto = s.nextLine();
            System.out.println("How much would you like to buy (in FIAT): ");
            double value = s.nextDouble();

            String _temp = null;
            String _crypto = currCrypto.getCrypto();
            String _value = currCrypto.getValue();
            boolean foundCrypto = false;
            double doubleValue = 0.0;
            while((_temp = reader.readLine()) != null)
            {
                String[] cryptos = _temp.split(",");
                _crypto = cryptos[0];
                

                if(_crypto.equals(crypto)){
                    foundCrypto = true;
                    _value = cryptos[1];
                    doubleValue = Double.parseDouble(_value);   
                    break;                
                }
                
            }
            //DECREASE MONEY FROM ACCOUNT - STOPS
            if(foundCrypto == true){
                double cryptoBought = value /doubleValue;
                System.out.println("You have successfully purchased "+cryptoBought+" in "+_crypto);
                //pAccNo = user.getAccNo();

                writer.write(pAccNo+","+ cryptoBought + "," + _crypto);
                writer.newLine();
                writer.close();
            }
            else{
                System.out.println("The crypto you are trying to buy does not exist in this system.");
            }


            

        }catch(Exception ex){
            System.out.print(ex.getMessage());
        }
    }

    // //SELL CRYPTO
    // public static void sellCrypto(Currencies currCrypto){
    //     Scanner s = new Scanner(System.in);
    //     String cryptoFile = "crypto.txt";

    //     try{
    //         Path path = Paths.get(cryptoFile.toString());
    //         InputStream input = Files.newInputStream(path);
    //         BufferedReader reader = new BufferedReader(new InputStreamReader(input));

    //         System.out.println("What crypto would you like to sell: ");
    //         String crypto = s.nextLine();
    //         System.out.println("How much would you like to sell (in FIAT): ");
    //         double value = s.nextDouble();

    //         String _temp = null;
    //         String _crypto = currCrypto.getCrypto();
    //         String _value = currCrypto.getValue();
    //         boolean foundCrypto = false;
    //         double doubleValue = 0.0;
    //         while((_temp = reader.readLine()) != null)
    //         {
    //             String[] cryptos = _temp.split(",");
    //             _crypto = cryptos[0];
                

    //             if(_crypto.equals(crypto)){
    //                 foundCrypto = true;
    //                 _value = cryptos[1];
    //                 doubleValue = Double.parseDouble(_value);   
    //                 break;                
    //             }
                
    //         }

    //         //INCREASE MONEY IN ACCOUNT
    //         if(foundCrypto == true){
    //             double cryptoSold = value /doubleValue;
    //             System.out.println("You have successfully sold "+cryptoSold+" in "+_crypto);
    //         }
    //         else{
    //             System.out.println("The crypto you are trying to buy does not exist in this system.");
    //         }


            

    //     }catch(Exception ex){
    //         System.out.print(ex.getMessage());
    //     }
    // }


    //FROM HERE - ADMIN METHODS
    public static void admin(){ 
        waitingApproval();
    }

    
    //LETS ADMIN APPROVE ACCOUNTS
    public static void waitingApproval(){
        Admin administrator = new Admin();
        String file = "waiting.txt";
        //String filename = "account.txt";
        try
            {
                Path path = Paths.get(file.toString());
                InputStream inputTmp = Files.newInputStream(path);
                BufferedReader readerTmp = new BufferedReader(new InputStreamReader(inputTmp));
                
                String line;

                while((line = readerTmp.readLine())!= null){
                   // System.out.println(line); //sanity check
                    administrator.adminApprove(line);
                }
            }catch(Exception ex){
                System.out.println(ex.getMessage());
            }
        }
}

   



   