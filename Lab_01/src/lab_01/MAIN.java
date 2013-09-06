/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package lab_01;

//Debugging imports;
import java.io.FileNotFoundException;

/**
 *
 * @author Nyefan
 */
public class MAIN {

  /**
   * @param args the command line arguments
   */
  public static void main(String[] args) {
//    Executive overseer = new Executive(args);
    
    //Debugging: use known filenames;
    String polyName = "D:\\Immutables\\Dropbox\\Coding\\EECS268\\Lab_01\\Lab01Polynomial.txt";
    String directiveName = "D:\\Immutables\\Dropbox\\Coding\\EECS268\\Lab_01\\Lab01Directives.txt";
    String[] newargs = {polyName, directiveName};
    try {
      Executive overseer = new Executive(newargs);
    } catch (FileNotFoundException ex) {
      System.err.println(ex.getMessage());
      System.exit(0);
    }
  }
}
