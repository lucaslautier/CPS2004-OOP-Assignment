import java.io.*;


public class Admin extends User{

    public void adminApprove(String line) throws IOException{
        
        String filename = "account.txt";
        
        //FileWriter fw = new FileWriter(filename, true);
        BufferedWriter fw = new BufferedWriter(new FileWriter(filename,true));

        fw.write(line);
        fw.newLine();
        fw.close();

        String file = "waiting.txt";
        PrintWriter writer = new PrintWriter(file);
        writer.print("");
        writer.close();
    }
      
}
