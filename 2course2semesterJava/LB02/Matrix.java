package com.company;

import java.util.Scanner;

public class Matrix {
    private int rows;
    private int columns;
    private int[][] matrix;

    private static void validation(final int number) {
        if (number <= 0) {
            throw new IllegalArgumentException("Rows and columns must be positiv");
        }
    }

    public Matrix() {
        this(1,1);
    }
    public Matrix(final int rows, final int columns) {
        int matrix[][] = new int[rows][columns];
        setMatrix(matrix,rows,columns);
    }
    public Matrix(final int[][] matrix, final int rows, final int columns) {
        setMatrix(matrix, rows, columns);
    }
    public Matrix(final Matrix matrix) {
        this(matrix.matrix, matrix.rows, matrix.columns);
    }

    public void setMatrix(final int[][] matrix, final int rows, final int columns) {
        setRows(rows);
        setColumns(columns);
        this.matrix = new int[rows][columns];
        for (int i = 0; i < rows; ++i) {
            System.arraycopy(matrix[i],0,this.matrix[i],0,columns);
        }
    }
    public void setRows(final int rows) {
        validation(rows);
        this.rows = rows;
    }
    public void setColumns(final int columns) {
        validation(columns);
        this.columns = columns;
    }

    public int getRows() {
        return this.rows;
    }
    public int getColumns() {
        return this.columns;
    }
    public int[][] getMatrix() {
        int[][] buffer = new int[getRows()][getColumns()];
        for (int i = 0; i < this.rows; ++i) {
            System.arraycopy(this.matrix[i],0,buffer[i],0,getColumns());
        }
        return buffer;
    }

    public void random(final int max) {
        for (int i = 0; i < this.rows; ++i) {
            for (int j = 0; j < this.columns; ++j) {
                this.matrix[i][j] = (int) (Math.random() * max);
            }
        }
    }

    public void display() {
        for (int i = 0; i < this.rows; ++i) {
            for (int element:this.matrix[i]) {
                System.out.print(element + " ");
            }
            System.out.println();
        }
    }
    public void enter(final int rows, final int columns) {
        Scanner scanner = new Scanner(System.in);
        setRows(rows);
        setColumns(columns);
        this.matrix = new int[rows][columns];
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < columns; ++j) {
                this.matrix[i][j] = scanner.nextInt();
            }
        }
    }

    public void task(final int columnNumber) {
        if (columnNumber < 0 || columnNumber > this.columns) {
            throw new IllegalArgumentException("This column doesn't exist");
        }
        int[] array = new int[this.rows];
        for (int i = 0; i < array.length; ++i) {
            array[i] = this.matrix[i][columnNumber];
        }

        for (int i = 0; i < array.length; i++) {
            for (int j = array.length - 1; j > i; j--) {
                if (array[j] < array[j - 1]) {
                    int temp = array[j];
                    array[j] = array[j - 1];
                    array[j - 1] = temp;

                    int[] tempArray = this.matrix[j];
                    this.matrix[j] = this.matrix[j - 1];
                    this.matrix[j - 1] = tempArray;
                }
            }
        }
    }
}
