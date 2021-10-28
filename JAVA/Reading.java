import java.io.*;
class Reading
{
    public static void main(String a[]) throws IOException
    {
        char c;
        BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
        System.out.println("Enter a letter");
        c=(char)br.read();
        System.out.println("Letter="+c);
    }
}