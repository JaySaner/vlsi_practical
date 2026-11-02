module full_adder_beh(
    input A, input B, input Cin,
    output reg Sum, output reg Cout
);
always @(*) begin
    Sum = A ^ B ^ Cin;
    Cout = (A & B) | (B & Cin) | (A & Cin);
end
endmodule
