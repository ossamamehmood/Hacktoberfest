module LogicGates (
  input A,
  input B,
  input [2:0] gateType, // 0: AND, 1: OR, 2: NOT, 3: NAND, 4: NOR, 5: XOR, 6: XNOR
  output O
);

  wire and_out, or_out, not_out, nand_out, nor_out, xor_out, xnor_out;

  // AND gate
  assign and_out = (gateType == 3'b000) ? (A & B) : 1'b0;

  // OR gate
  assign or_out = (gateType == 3'b001) ? (A | B) : 1'b0;

  // NOT gate
  assign not_out = (gateType == 3'b010) ? (~A) : 1'b0;

  // NAND gate
  assign nand_out = (gateType == 3'b011) ? ~(A & B) : 1'b0;

  // NOR gate
  assign nor_out = (gateType == 3'b100) ? ~(A | B) : 1'b0;

  // XOR gate
  assign xor_out = (gateType == 3'b101) ? (A ^ B) : 1'b0;

  // XNOR gate
  assign xnor_out = (gateType == 3'b110) ? ~(A ^ B) : 1'b0;

  // Output selection based on gateType
  always @(*) begin
    case (gateType)
      3'b000: O = and_out;
      3'b001: O = or_out;
      3'b010: O = not_out;
      3'b011: O = nand_out;
      3'b100: O = nor_out;
      3'b101: O = xor_out;
      default: O = xnor_out;
    endcase
  end

endmodule


