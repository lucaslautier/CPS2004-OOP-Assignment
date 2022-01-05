package Task2;

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

public class Main{

    public static void main(String[] args)
    {
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
                login();
                break;
            
            case 3:
                exit = true;
                s.close();
                break;
            }
        
        }while(!exit);
    }

    public static void login()
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
                String _user;
                String _pass;
                boolean found = false;
                while((_temp = reader.readLine()) != null)
                {
                    String[] account = _temp.split(",");
                    _user = account[0];
                    _pass = account[1];

                    if(_user.equals(username) && _pass.equals(password)){
                        found = true;
                    }
                }
                if(found == true){
                    System.out.println("Login Successful");
                }
                else{
                    System.out.println("Credentials entered did not match");
                }
                
                System.out.println("Press any key to continue...");
                String cont = s.nextLine();
            }catch(Exception ex){
                System.out.print(ex.getMessage());
                s.close();
            }
            
    }

    public static void createAccount()
    {
        Scanner s = new Scanner(System.in);
            String filename = "account.txt";
            try{
                Path path = Paths.get(filename.toString());
                OutputStream output = new BufferedOutputStream(Files.newOutputStream(path, APPEND));
                BufferedWriter writer = new BufferedWriter(new OutputStreamWriter(output));
                System.out.println("CREATE ACCOUNT");
                System.out.println("Enter username: ");
                String username = s.nextLine();
                System.out.println(("Enter password: "));
                String password = s.nextLine();
            
                writer.write(username + "," + password);
                writer.newLine();
                System.out.println("Your account has been created successfully");
                writer.close();
                output.close();

                System.out.println("Press any key to continue...");
                String cont = s.nextLine();
                //new Main();

            }catch(Exception ex){
                System.out.println(ex.getMessage());
                s.close();
            }
            
        

    }
}
   



