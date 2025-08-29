package Stratagy_pattern;

///Stragegy Inferface 
interface PaymentStrategy {
    void pay(int amount);
}

// Concreate Strategies
class CreditCardPayment implements PaymentStrategy {
    private String cardNumber;

    public CreditCardPayment(String cardNumber) {
        this.cardNumber = cardNumber;
    }

    @Override
    public void pay(int amount) {
        System.out.println("Paid $" + amount + " using Credit Card: " + cardNumber);
    }
}

class PayPalPayment implements PaymentStrategy {
    private String email;

    public PayPalPayment(String email) {
        this.email = email;
    }

    @Override
    public void pay(int amount) {
        System.out.println("Paid $" + amount + " using PayPal: " + email);
    }
}

class UpiPayment implements PaymentStrategy {
    private String upiId;

    public UpiPayment(String upiId) {
        this.upiId = upiId;
    }

    @Override
    public void pay(int amount) {
        System.out.println("Paid $" + amount + " using UPI ID: " + upiId);
    }
}

/// Contex (Uses a strategy)
class ShoppingCart {
    private PaymentStrategy paymentStrategy;

    // Inject strategy at runtime
    public void setPaymentStrategy(PaymentStrategy paymentStrategy) {
        this.paymentStrategy = paymentStrategy;
    }

    public void checkout(int amount) {
        if (paymentStrategy == null) {
            System.out.println("Please select a payment method before checkout.");
        } else {
            paymentStrategy.pay(amount);
        }
    }
}

// Usage
public class Payment_Stratagy {
    public static void main(String[] args) {
        ShoppingCart cart = new ShoppingCart();

        // Pay with Credit Card
        cart.setPaymentStrategy(new CreditCardPayment("1234-5678-9876-5432"));
        cart.checkout(100);

        // Pay with PayPal
        cart.setPaymentStrategy(new PayPalPayment("user@example.com"));
        cart.checkout(200);

        // Pay with UPI
        cart.setPaymentStrategy(new UpiPayment("user@upi"));
        cart.checkout(50);
    }
}

// constructor INjection
// package Stratagy_pattern;

// /// Strategy Interface
// interface PaymentStrategy {
// void pay(int amount);
// }

// // Concrete Strategies
// class CreditCardPayment implements PaymentStrategy {
// private String cardNumber;

// public CreditCardPayment(String cardNumber) {
// this.cardNumber = cardNumber;
// }

// @Override
// public void pay(int amount) {
// System.out.println("Paid $" + amount + " using Credit Card: " + cardNumber);
// }
// }

// class PayPalPayment implements PaymentStrategy {
// private String email;

// public PayPalPayment(String email) {
// this.email = email;
// }

// @Override
// public void pay(int amount) {
// System.out.println("Paid $" + amount + " using PayPal: " + email);
// }
// }

// class UpiPayment implements PaymentStrategy {
// private String upiId;

// public UpiPayment(String upiId) {
// this.upiId = upiId;
// }

// @Override
// public void pay(int amount) {
// System.out.println("Paid $" + amount + " using UPI ID: " + upiId);
// }
// }

// /// Context (uses a strategy)
// class ShoppingCart {
// private PaymentStrategy paymentStrategy;

// // ✅ Constructor Injection
// public ShoppingCart(PaymentStrategy paymentStrategy) {
// this.paymentStrategy = paymentStrategy;
// }

// public void checkout(int amount) {
// paymentStrategy.pay(amount);
// }
// }

// // Usage
// public class Payment_Stratagy {
// public static void main(String[] args) {
// // Pay with Credit Card
// ShoppingCart cart1 = new ShoppingCart(new
// CreditCardPayment("1234-5678-9876-5432"));
// cart1.checkout(100);

// // Pay with PayPal
// ShoppingCart cart2 = new ShoppingCart(new PayPalPayment("user@example.com"));
// cart2.checkout(200);

// // Pay with UPI
// ShoppingCart cart3 = new ShoppingCart(new UpiPayment("user@upi"));
// cart3.checkout(50);
// }
// }
