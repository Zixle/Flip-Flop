# Flip-Flop

This project is a Flip-Flop Circuit Simulator implemented in C++, designed to simulate basic digital logic flip-flops such as SR, JK, D, and T flip-flops. The program allows users to configure inputs, define flip-flop types, and observe the outputs based on given logic. It's purpose was to practice inhertiance and polymorphism programming concepts. 


Each flip flop should has a preset (PR), clear (CLR), and clock (CLK) inputs and outputs Q and Qn.
All were accessed using functions. The inputs have the behavior:
• PR : Q = true, Qn = false
• CLR : Q = false, Qn = true
• D, J, K, T : save the input values
• Clock : set Q and Qn according to the behavior of the flip flop (Qn should always be not Q)
• D : Q = D
• JK : Q = (Q and not K) or (not Q && J)
• T: if T Q = not Q, else unchanged
