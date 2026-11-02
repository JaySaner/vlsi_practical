module ALU_3bit(
    input [2:0] A,
    input [2:0] B,
    input [2:0] sel,
    output reg [2:0] Y,
    output reg Cout
);
always @(*) begin
    Y = 3'b000;
    Cout = 1'b0;
    case (sel)
        3'b000: {Cout,Y} = {1'b0,A} + {1'b0,B};
        3'b001: {Cout,Y} = {1'b0,A} - {1'b0,B};
        3'b010: Y = A & B;
        3'b011: Y = A | B;
        3'b100: Y = A ^ B;
        3'b101: Y = ~A;
        3'b110: Y = A << 1;
        3'b111: Y = A >> 1;
        default: begin Y=3'b000; Cout=1'b0; end
    endcase
end
endmodule
