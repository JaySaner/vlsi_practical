module half_adder(
    input A, input B,
    output Sum, output Carry
);
assign Sum = A ^ B;
assign Carry = A & B;
endmodule

module full_adder_2ha(
    input A, input B, input Cin,
    output Sum, output Cout
);
wire s1, c1, c2;
half_adder HA1(.A(A), .B(B), .Sum(s1), .Carry(c1));
half_adder HA2(.A(s1), .B(Cin), .Sum(Sum), .Carry(c2));
assign Cout = c1 | c2;
endmodule
