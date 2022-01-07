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

    public static void main(String[] args)
    {
        User user = new User();
        Scanner s = new Scanner(System.in);
        int option = 0;
        boolean exit = false;

        do{
        
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
                login(user);
                break;
            
            case 3:
                exit = true;
                s.close();
                break;
            
            case 99:
                admin();
                break;
        }
        
        }while(!exit);
    }

    public static void login(User tmpUser)
    {
        
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
                String _user = tmpUser.getUser();
                String _pass = tmpUser.getPass();
    
                boolean _reg = tmpUser.getReg();
                boolean found = false;
                while((_temp = reader.readLine()) != null)
                {
                    String[] account = _temp.split(",");
                    _user = account[1];
                    _pass = account[2];
                   
                    
                    if(_user.equals(username) && _pass.equals(password) && tmpUser.getReg() == true){
                        found = true;
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
            
    }

    public static User createAccount()
    {
        User tmpUser = new User();
        Scanner s = new Scanner(System.in);
        String filename = "account.txt";
        //System.out.println(new File("account.txt").getAbsoluteFile());
        

            try{
                Path path = Paths.get(filename.toString());
                OutputStream output = new BufferedOutputStream(Files.newOutputStream(path, APPEND));
                BufferedWriter writer = new BufferedWriter(new OutputStreamWriter(output));
                int accNo = 0;
                Scanner sc = new Scanner(path);
                while(sc.hasNextLine()){
                    sc.nextLine();
                    accNo++;
                }
                //System.out.println(" "+accNo );
                tmpUser.setAccNo(accNo);
                sc.close();
                // BufferedReader reader = new BufferedReader(new FileReader("account.txt"));
                // int lines = 0;
                // while(reader.readLine() != null){
                //     lines++;
                // }
                // reader.close();
                //Getting user details and calling set methods
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

                //output to ask for money
                writer.write(tmpUser.getAccNo()+","+tmpUser.getUser() + "," + tmpUser.getPass()+','+tmpUser.getMoney()+","+tmpUser.getReg());
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
            
        //enter initial investment
        return tmpUser;
    }

    
    public static void admin(){
        User tmpUser = new User();
        System.out.println("User Details:");
        tmpUser.getUser();


    }
}
   



   