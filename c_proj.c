#include <stdio.h>
#include <math.h>

int main() {
    // Initializing the variables
    float width = 15;
    float depth;    // To be entered by the user
    float slope = 0.0015;
    float roughness_coefficient = 0.014;
    float desired_flow = 1000;
    float desired_flow_limits_offset = 1;
    
    printf("Enter your initial guess for the channel depth when the flow is 1000.0000 cubic feet per second\n\n");
    
    printf("Enter guess > ");
    scanf("%f", &depth);
    
    // Guess Loop
    do {
        // Area Calculation
        float area = width * depth;
        
        // Hydraulic Radius Calculation
        float hydraulic_radius = depth * width / (2 * depth + width);
        
        // Manning's Equation
        float calculated_flow = 1.486 * area * pow(hydraulic_radius, 2.0/3.0) * pow(slope, 0.5) / roughness_coefficient;
        
        printf("%f", calculated_flow);
        
        // Print the required info
        printf("\nDepth: %f\n", depth);
        printf("Flow: %f cfs\n", calculated_flow);
        printf("Target: %f cfs\n", desired_flow);
        printf("Difference: %f\n", calculated_flow - desired_flow);
        printf("Error: %f\n\n", (calculated_flow - desired_flow) / desired_flow * 100);
        
        // Tolerance Condition
        if (fabs(calculated_flow - desired_flow) <= desired_flow_limits_offset) {
            printf("Congo! It's accurate!");
            break;
        }
        else if (calculated_flow < desired_flow) {
            printf("Flow is too low...\n\n");
        }
        else {
            printf("Flow is too high...\n\n");
        }
        
        printf("Enter guess > ");
        scanf("%f", &depth);
    }
    while (1);
    
    return 0;
}