module decoder_38_struct(
    input A, input B, input C,
    output [7:0] Y
);
wire nA, nB, nC;
not (nA,A);
not (nB,B);
not (nC,C);
and (Y[0],nA,nB,nC);
and (Y[1],nA,nB,C);
and (Y[2],nA,B,nC);
and (Y[3],nA,B,C);
and (Y[4],A,nB,nC);
and (Y[5],A,nB,C);
and (Y[6],A,B,nC);
and (Y[7],A,B,C);
endmodule
