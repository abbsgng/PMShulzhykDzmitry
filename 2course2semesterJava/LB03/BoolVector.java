package com.company.LB03;

import java.util.Arrays;

public class BoolVector extends Vector {

    public BoolVector() {
        int array[] = new int[1];
        setVector(array);
    }

    public BoolVector(final int size) {
        super(size);
    }

    public BoolVector(final int[] array) {
        setVector(array);
    }

    public BoolVector(final BoolVector vector) {
        super(vector);
    }

    public void setVector(final int[] array) {
        setSize(array.length);
        for (int i = 0; i < array.length; ++i) {
            if (array[i] != 1 && array[i] != 0) {
                int clean[] = new int[1];
                setVector(clean);
                return;
            } else {
                super.setVector(array);
            }
        }
    }

    public int countOfOne() {
        int count = 0;
        int array[] = this.getArray();
        for (int element : array) {
            if (element == 1) {
                count++;
            }
        }
        return count;
    }

    public int firstLeftOne() {
        int index = 0;
        int array[] = this.getArray();
        for (int i = 0; i < this.getSize(); ++i) {
            if (array[i] == 1) {
                index = i;
                break;
            }
        }
        return index;
    }

    public static BoolVector operationAND(final BoolVector lhs, final BoolVector rhs) {
        if (lhs.getSize() != rhs.getSize()) {
            throw new IllegalArgumentException("Sizes must be equal");
        }
        int result[] = new int[lhs.getSize()];
        int array1[] = lhs.getArray();
        int array2[] = rhs.getArray();

        for (int i = 0; i < result.length; ++i) {
            result[i] = array1[i] == array2[i] && array1[i] != 0 && array2[i] != 0 ? 1 : 0;
        }
        return new BoolVector(result);
    }

    public static BoolVector operationOR(final BoolVector lhs, final BoolVector rhs) {
        if (lhs.getSize() != rhs.getSize()) {
            throw new IllegalArgumentException("Sizes must be equal");
        }
        int result[] = new int[lhs.getSize()];
        int array1[] = lhs.getArray();
        int array2[] = rhs.getArray();

        for (int i = 0; i < result.length; ++i) {
            result[i] = array1[i] == 1 || array2[i] == 1 ? 1 : 0;
        }
        return new BoolVector(result);
    }

    public static BoolVector operationXOR(final BoolVector lhs, final BoolVector rhs) {
        if (lhs.getSize() != rhs.getSize()) {
            throw new IllegalArgumentException("Sizes must be equal");
        }
        int result[] = new int[lhs.getSize()];
        int array1[] = lhs.getArray();
        int array2[] = rhs.getArray();

        for (int i = 0; i < result.length; ++i) {
            result[i] = (array1[i] + array2[i]) % 2;
        }
        return new BoolVector(result);
    }

    public static BoolVector inversion(final BoolVector vector) {
        int result[] = new int[vector.getSize()];

        for (int i = 0; i < result.length; ++i) {
            result[i] = vector.getArray()[i] == 1 ? 0 : 1;
        }
        return new BoolVector(result);
    }

}
