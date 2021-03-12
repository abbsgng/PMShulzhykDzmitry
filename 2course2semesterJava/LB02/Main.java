package com.company;

public class Main {

    public static void main(String[] args) {
        System.out.println("Enter the matrix:");
        Matrix matrix = new Matrix();
        matrix.enter(5, 5);
        System.out.println();
        System.out.println("Sorted:");
        matrix.task(2);
        matrix.display();
        System.out.println();
        matrix.random(100);
        System.out.println("Random:");
        matrix.display();

    }
}
