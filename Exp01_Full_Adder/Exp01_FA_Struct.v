module full_adder_struct(
    input A, input B, input Cin,
    output Sum, output Cout
);
wire x1, a1, a2, a3;
xor (x1, A, B);
xor (Sum, x1, Cin);
and (a1, A, B);
and (a2, B, Cin);
and (a3, A, Cin);
or  (Cout, a1, a2, a3);
endmodule
