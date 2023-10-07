
module LogicGates_tb;

  reg A, B;
  reg [2:0] gateType;
  wire O;

  LogicGates uut (
    .A(A),
    .B(B),
    .gateType(gateType),
    .O(O)
  );

  initial begin
    $display("Testing LogicGates Module");

    // Test AND gate
    A = 1'b0;
    B = 1'b0;
    gateType = 3'b000; // AND
    #10;
    $display("AND gate: A=%b, B=%b, O=%b", A, B, O);

    // Test OR gate
    A = 1'b1;
    B = 1'b0;
    gateType = 3'b001; // OR
    #10;
    $display("OR gate: A=%b, B=%b, O=%b", A, B, O);

    // Test NOT gate
    A = 1'b0;
    gateType = 3'b010; // NOT
    #10;
    $display("NOT gate: A=%b, O=%b", A, O);

    // Test NAND gate
    A = 1'b1;
    B = 1'b1;
    gateType = 3'b011; // NAND
    #10;
    $display("NAND gate: A=%b, B=%b, O=%b", A, B, O);

    // Test NOR gate
    A = 1'b0;
    B = 1'b0;
    gateType = 3'b100; // NOR
    #10;
    $display("NOR gate: A=%b, B=%b, O=%b", A, B, O);

    // Test XOR gate
    A = 1'b1;
    B = 1'b0;
    gateType = 3'b101; // XOR
    #10;
    $display("XOR gate: A=%b, B=%b, O=%b", A, B, O);

    // Test XNOR gate
    A = 1'b1;
    B = 1'b1;
    gateType = 3'b110; // XNOR
    #10;
    $display("XNOR gate: A=%b, B=%b, O=%b", A, B, O);

    $finish;
  end

endmodule
