package Decorator_pattern;

// Component Interface
interface Beverage {
    String getDescription();

    double getCost();
}

// Concrete Components
class Coffee implements Beverage {
    @Override
    public String getDescription() {
        return "Simple Coffee";
    }

    @Override
    public double getCost() {
        return 5.0;
    }
}

class Tea implements Beverage {
    @Override
    public String getDescription() {
        return "Simple Tea";
    }

    @Override
    public double getCost() {
        return 3.0;
    }
}

// Abstract Decorator
abstract class BeverageDecorator implements Beverage {
    protected Beverage beverage;

    public BeverageDecorator(Beverage beverage) {
        this.beverage = beverage;
    }

    @Override
    public String getDescription() {
        return beverage.getDescription();
    }

    @Override
    public double getCost() {
        return beverage.getCost();
    }
}

// Concrete Decorators
class MilkDecorator extends BeverageDecorator {
    public MilkDecorator(Beverage beverage) {
        super(beverage);
    }

    @Override
    public String getDescription() {
        return beverage.getDescription() + ", Milk";
    }

    @Override
    public double getCost() {
        return beverage.getCost() + 2.0;
    }
}

class SugarDecorator extends BeverageDecorator {
    public SugarDecorator(Beverage beverage) {
        super(beverage);
    }

    @Override
    public String getDescription() {
        return beverage.getDescription() + ", Sugar";
    }

    @Override
    public double getCost() {
        return beverage.getCost() + 1.0;
    }
}

// Usage
public class Decorator_pattern_abstract {
    public static void main(String[] args) {
        // Coffee
        Beverage coffee = new Coffee();
        System.out.println(coffee.getDescription() + " $" + coffee.getCost());

        Beverage milkCoffee = new MilkDecorator(coffee);
        System.out.println(milkCoffee.getDescription() + " $" + milkCoffee.getCost());

        Beverage sugarMilkCoffee = new SugarDecorator(new MilkDecorator(coffee));
        System.out.println(sugarMilkCoffee.getDescription() + " $" + sugarMilkCoffee.getCost());

        // Tea
        Beverage tea = new Tea();
        System.out.println(tea.getDescription() + " $" + tea.getCost());

        Beverage milkTea = new MilkDecorator(tea);
        System.out.println(milkTea.getDescription() + " $" + milkTea.getCost());

        Beverage sugarMilkTea = new SugarDecorator(new MilkDecorator(tea));
        System.out.println(sugarMilkTea.getDescription() + " $" + sugarMilkTea.getCost());
    }
}
