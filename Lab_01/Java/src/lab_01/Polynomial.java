/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package lab_01;

/**
 *
 * @author Nyefan
 */
public class Polynomial {
  
  private static int MAX_DEGREE = 20;
  private double[] coefficients = new double[MAX_DEGREE]; 
  private int length;
  private String printable = "";
  private double sum = 0;
  
  public Polynomial(double[] coefficients) throws IllegalArgumentException {
    if (coefficients.length > MAX_DEGREE) {
      throw new IllegalArgumentException("A Polynomial cannot be initialized with a degree greater than 20;");
    }
    this.length = coefficients.length;
    System.arraycopy(coefficients, 0, this.coefficients, 0, this.length);
  }
  
  public Polynomial add(Polynomial p2, boolean toPrint) {
    double [] tempCoeff = this.coefficients;
    for(int i = 0; i < Math.max(this.length, p2.length); i++) {
      tempCoeff[i] += p2.coefficients[i];
    }
    
    Polynomial returnable = new Polynomial(tempCoeff);
    
    if (toPrint) {
      System.out.print("\nThe sum of the polynomials,\n ");
      print(); System.out.print(" and "); p2.print();
      System.out.print(" is ");
      returnable.print();
    }
    return this;
  }
  
  public Polynomial differentiate(boolean toPrint) {
    double[] coeff = new double[this.length-1];
    for(int i = 0; i < this.length-1; i++) {
      coeff[i] = (i+1)*coefficients[i+1];
    }
    
    Polynomial returnable = new Polynomial(coeff);
    
    if (toPrint) {
      System.out.print("\nThe derivative of the polynomial,\n ");
      print();
      System.out.print(" is ");
      returnable.print();
    }
    
    return returnable;
  }
  
  public double evaluate(double x, boolean toPrint) {
    if (sum == 0) {
      for(int i = 0; i < this.length; i++) {
        sum += coefficients[i]*Math.pow(x,i);
      }
    }
    if (toPrint) {
      System.out.print("\nThe polynomial,\n ");
      print();
      System.out.println(" evaluated at " + x + "\n is " + formatDouble(sum) + ".");
    }
    return sum;
  }
  
  public void print() {
    if (!printable.equals("")) {
      System.out.println(printable);
    } else {
      parseCoefficients();
      System.out.println(printable);
    }
  }
  
  private double formatDouble(double x) {
    return ((double)( Math.round(x*10000)))/10000;
  }
  
  private void parseCoefficients() {
    printable = "";
    printable += formatDouble(coefficients[0]);
    for(int i = 1; i < length-1; i++) {
      if(this.coefficients[i] != 0) {
        printable += " + " + formatDouble(this.coefficients[i]) + "x^" + i;
      }
    }
  }
}
