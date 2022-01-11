public class User {
    public String user = "";

    public String pass = "";

    // do the same for money
    public long accNo;
    public double money;
    
    public boolean isLoggedIn;




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

public void setLogBool(boolean isLoggedIn){
    this.isLoggedIn = isLoggedIn;
}

public String getUser(){
    return user;
}

public String getPass(){
    return pass;
}

public long getAccNo(){
    return accNo;
}

public double getMoney(){
    return money;
}

public boolean getLogBool(){
    return isLoggedIn;
}
}