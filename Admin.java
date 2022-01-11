import java.util.*;
import java.nio.file.*;
import java.io.*;
import static java.nio.file.StandardOpenOption.*;
import java.nio.charset.*;
import java.util.stream.*;


public class Admin extends User{

    public void adminApprove(String line, boolean isApproved, boolean toClear) throws IOException{
        
        String filename = "account.txt";
        String wFile = "waiting.txt";
        
         if(isApproved){
            BufferedWriter fw = new BufferedWriter(new FileWriter(filename,true));
            fw.write(line);
            fw.newLine();
            fw.close();
        }
        


        if(toClear){
            PrintWriter writer = new PrintWriter(wFile);
            writer.print("");
            writer.close();
        }
        
       
    }
      
}
