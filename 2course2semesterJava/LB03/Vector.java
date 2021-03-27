package com.company.LB03;

import java.util.Arrays;

public class Vector {
    private int size;
    private int[] array;

    private static void validation(final int number) {
        if (number <= 0) {
            throw new IllegalArgumentException("Size must be positiv");
        }
    }

    public Vector() {
        int array[] = new int[1];
        setVector(array);
    }

    public Vector(final int size) {
        validation(size);
        int array[] = new int[size];
        setVector(array);
    }

    public Vector(final int[] array) {
        setVector(array);
    }

    public Vector(final Vector vector) {
        this(vector.array);
    }

    public void setSize(final int size) {
        validation(size);
        this.size = size;
    }

    public void setVector(final int[] array) {
        setSize(array.length);
        this.array = Arrays.copyOf(array, this.size);
    }

    public int getSize() {
        return this.size;
    }

    public int[] getArray() {
        return Arrays.copyOf(this.array, this.size);
    }

    public String toString() {
        return Arrays.toString(this.array);
    }
}
