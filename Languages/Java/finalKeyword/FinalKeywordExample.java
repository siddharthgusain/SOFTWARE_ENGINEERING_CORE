package Languages.Java.finalKeyword;

public final class FinalKeywordExample { // can't be extended
    final int MAX_VALUE = 10; // Constant
    final int[] arr = { 1, 23, 4 }; // Can;t assign new array

    final void change() { // Final Method can't be overridden by Child class
        // this.arr = new int[5]; // not possible
        arr[0] = 22; // possible
    }

}

// there's no const keyword in java