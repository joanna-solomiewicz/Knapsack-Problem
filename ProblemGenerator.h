class ProblemInstance;

class ProblemGenerator {
public:
    static ProblemInstance* generateProblem();

private:
    static int getCapacity();
    static int getObjectsQuantity();
    static void generateObjectsList(ProblemInstance* problemInstance);

};

