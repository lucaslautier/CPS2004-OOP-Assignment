public class Admin extends User{

    void adminApprove(User user){
       
        boolean approved = user.getReg();

        approved = true;

        user.setReg(approved);
        
    }
      
}
