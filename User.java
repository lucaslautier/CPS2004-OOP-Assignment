public class User {
    public String user = "";

    public String pass = "";

    // do the same for money
    public long accNo;
    public double money;
    public boolean isReg = false;




public void setUser(String username){
    this.user=username;
}

public void setPass(String password){
    this.pass=password;
}

public void setAccNo(long accNo){
    this.accNo = accNo;
}

public void setMoney(double money){
    this.money = money;
}

public void setReg(boolean isReg){
    this.isReg = isReg;
}

public String getUser(){
    return user;
}

public String getPass(){
    return pass;
}

public boolean getReg(){
    return isReg;
}

public long getAccNo(){
    return accNo;
}

public double getMoney(){
    return money;
}
}