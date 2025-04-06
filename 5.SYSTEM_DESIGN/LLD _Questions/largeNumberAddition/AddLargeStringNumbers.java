package com.largeNumberAddition;

class InvalidInputException extends Exception {
    InvalidInputException(String message) {
        super(message);
    }
}

public class AddLargeStringNumbers {

    // Validate input to ensure it contains only digits and commas
    public static void validateInput(String input) throws InvalidInputException {
        if (!input.matches("[0-9,]+")) {
            throw new InvalidInputException("Input contains invalid characters. Only digits and commas are allowed.");
        }
    }

    private static String formatResult(String input) {
        if(input.length() <=3 )
            return input;

        StringBuilder output = new StringBuilder();
        int count = 0;

        for(int i = input.length() - 1; i >= 0; i--) {
            output.append(input.charAt(i));
            count++;

            if(count % 3 == 0 && i!=0){
                output.append(",");
            }
        }

        return output.reverse().toString();
    }

    private static String addStringNumbers(String str1, String str2) throws InvalidInputException {
        validateInput(str1);
        validateInput(str2);
        str1 = str1.replace(",", "");
        str2 = str2.replace(",", "");

        int firstPointer = str1.length() - 1;
        int secondPointer = str2.length() - 1;
        int carry = 0;
        StringBuilder result = new StringBuilder();

        while(firstPointer >= 0 || secondPointer >= 0 || carry != 0 ) {
            int firstDigit = firstPointer >= 0 ? str1.charAt(firstPointer) - '0' : 0;
            int secondDigit = secondPointer >= 0 ? str2.charAt(secondPointer) - '0' : 0;

            int sum = firstDigit + secondDigit + carry;
            carry = sum / 10;
            result.append(sum % 10);
            firstPointer--;
            secondPointer--;
        }

        String withoutFormat =  result.reverse().toString();

        return formatResult(withoutFormat);
    }

    private static String nthFabonacci(int n) throws InvalidInputException {
        if(n== 1) return "1";
        if(n==2) return "1";

        String first = "1";
        String second = "1";
        String third = "";

        for(int i=3 ; i<=n ; i++){
            third = addStringNumbers(first, second);
            first = second;
            second = third;
        }

        return third;
    }

    public static void main(String[] args) {

        try{
            String num1 = "123&4";
            String num2 = "1234";

            System.out.println(addStringNumbers(num1, num2));
            System.out.println(nthFabonacci(1000));
        }catch(Exception e){
            System.out.println(e);
        }

    }

}
