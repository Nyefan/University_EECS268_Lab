/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package lab_01;


import java.io.Closeable;
import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;

/**
 *
 * @author Nyefan
 */
public class Executive implements Closeable {
  
  private static int MAX_DEGREE = 20;
  private static int MAX_POLYNOMIAL = 10;
  private Polynomial[] polynomials = new Polynomial[MAX_POLYNOMIAL];
  
  public Executive(String[] args) throws FileNotFoundException {
    if(args.length == 2) {
      parsePolynomials(args[0]);
      parseDirectives(args[1]);
    } else {
      throw new IllegalArgumentException("An Executive can only be initialized with a String[2]");
    }
  }
  
  private void parsePolynomials(String fileName) throws FileNotFoundException {
    Scanner input = new Scanner(new File(fileName));
    int polyNum = 0;
    
    while(input.hasNext()) {      
      if (polyNum >= MAX_POLYNOMIAL) {
        System.err.println("Input file has more than " + MAX_POLYNOMIAL + " polynomials.  Only the first " + MAX_POLYNOMIAL + " will be processed");
      }
      
      if(!input.hasNextInt()) {
        System.err.println("Input file is improperly formatted at Polynomial " + polyNum + ".  The parser will now skip to the nextLine beginning with an int.");
        while(!input.hasNextInt()) {
          input.nextLine();
        } if(!input.hasNext()) {break;}
      }
      
      double[] tempPoly = new double[MAX_DEGREE];
      int tempSize = input.nextInt();
      for(int i = 0; i <= tempSize; i++) {
        tempPoly[i] = input.nextDouble();
      }
      polynomials[polyNum++] = new Polynomial(tempPoly);
//      Debugging;
      polynomials[polyNum-1].print();
//      System.out.print(input.next());
    }
    System.out.println("\n");
  }
  
  private void parseDirectives(String fileName) throws FileNotFoundException {
    Scanner input = new Scanner(new File(fileName));
    
    while (input.hasNext()) {
      String command = input.next();
      
      if (command.equalsIgnoreCase("add")) {
        polynomials[input.nextInt()].add(polynomials[input.nextInt()], true);
      } else if (command.equalsIgnoreCase("differentiate")) {
        polynomials[input.nextInt()].differentiate(true);
      } else if (command.equalsIgnoreCase("evaluate")) {
        polynomials[input.nextInt()].evaluate(input.nextDouble(), true);
      } else if (command.equalsIgnoreCase("print")) {
        polynomials[input.nextInt()].print();
      } else {
        throw new IllegalArgumentException("Unknown or unsupported Directive operation.");
      }
    }
    
  }

  @Override
  public void close() {
    System.exit(0);
  }
}
