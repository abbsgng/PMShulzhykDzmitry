package com.company.LB03;

public class Main {
    public static void main(String[] args) {
        int array1[] = new int[7];
        for (int i = 0; i < 7; i += 2) {
            array1[i] = 1;
        }
        BoolVector vector1 = new BoolVector(array1);
        int array2[] = new int[7];
        for (int i = 0; i < 7; i += 3) {
            array2[i] = 1;
        }
        BoolVector vector2 = new BoolVector(array2);

        BoolVector result = BoolVector.inversion(vector2);
        System.out.println("Inversion \n" + vector2);
        System.out.println("Result: " + result + "\n");

        result = BoolVector.operationAND(vector1, vector2);
        System.out.println("AND \n" + vector1 + "\n" + vector2);
        System.out.println("Result: " + result + "\n");

        result = BoolVector.operationOR(vector1, vector2);
        System.out.println("OR \n" + vector1 + "\n" + vector2);
        System.out.println("Result: " + result + "\n");

        result = BoolVector.operationXOR(vector1, vector2);
        System.out.println("XOR \n" + vector1 + "\n" + vector2);
        System.out.println("Result: " + result + "\n");
    }
}
