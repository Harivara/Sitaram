package Decorator_pattern;

// Base Coffee class
class Coffee {
    public String getDescription() {
        return "Simple Coffee";
    }

    public double getCost() {
        return 5.0;
    }
}

// Base Tea class
class Tea {
    public String getDescription() {
        return "Simple Tea";
    }

    public double getCost() {
        return 3.0;
    }
}

// Milk decorator for Coffee
class MilkCoffee extends Coffee {
    private Coffee coffee;

    public MilkCoffee(Coffee coffee) {
        this.coffee = coffee;
    }

    @Override
    public String getDescription() {
        return coffee.getDescription() + ", Milk";
    }

    @Override
    public double getCost() {
        return coffee.getCost() + 2.0;
    }
}

// Sugar decorator for Coffee
class SugarCoffee extends Coffee {
    private Coffee coffee;

    public SugarCoffee(Coffee coffee) {
        this.coffee = coffee;
    }

    @Override
    public String getDescription() {
        return coffee.getDescription() + ", Sugar";
    }

    @Override
    public double getCost() {
        return coffee.getCost() + 1.0;
    }
}

// Milk decorator for Tea
class MilkTea extends Tea {
    private Tea tea;

    public MilkTea(Tea tea) {
        this.tea = tea;
    }

    @Override
    public String getDescription() {
        return tea.getDescription() + ", Milk";
    }

    @Override
    public double getCost() {
        return tea.getCost() + 2.0;
    }
}

// Sugar decorator for Tea
class SugarTea extends Tea {
    private Tea tea;

    public SugarTea(Tea tea) {
        this.tea = tea;
    }

    @Override
    public String getDescription() {
        return tea.getDescription() + ", Sugar";
    }

    @Override
    public double getCost() {
        return tea.getCost() + 1.0;
    }
}

// Main Class
public class Decorator_pattern_class {
    public static void main(String[] args) {
        // Coffee
        Coffee coffee = new Coffee();
        System.out.println(coffee.getDescription() + " $" + coffee.getCost());

        Coffee milkCoffee = new MilkCoffee(coffee);
        System.out.println(milkCoffee.getDescription() + " $" + milkCoffee.getCost());

        Coffee sugarMilkCoffee = new SugarCoffee(milkCoffee);
        System.out.println(sugarMilkCoffee.getDescription() + " $" + sugarMilkCoffee.getCost());

        // Tea
        Tea tea = new Tea();
        System.out.println(tea.getDescription() + " $" + tea.getCost());

        Tea milkTea = new MilkTea(tea);
        System.out.println(milkTea.getDescription() + " $" + milkTea.getCost());

        Tea sugarMilkTea = new SugarTea(new MilkTea(tea));
        System.out.println(sugarMilkTea.getDescription() + " $" + sugarMilkTea.getCost());
    }
}
