#pragma once

#include <QVector>

// �����������: ������� ����������� ������, ������ � char, �� ���� ����������,
// ����� ����� ��� ��������������� �� �����

class ParsysX
{
public:
    ParsysX();
    int sizeOf(const int&) const;
private:
    const QVector<int> params_sizes {
        4, // ��� �� �����  // ��  // f // 0 // 1
        4, // �������� �� ������  // �� reerr  // f // 1 // 1
        4, // �������� �� �����  // ppm c  // f // 2 // 1
        4, // �������� �� ������  // ppm c  // f // 3 // 1
        4, // ������� ������  // ��/�  // f // 4 // 1
        4, // ������ �� ������  // �*�  // f // 5 // 1
        4, // ��������� �� �����  // ��/�3 m  // f // 6 // 1
        4, // ��������� �� ������  // ��/�3 m  // f // 7 // 1
        4, // ����������� �� �����  // ���  // f // 8 // 1
        4, // ����������� �� �����  // ���  // f // 9 // 1
        4, // ����� ������� ���. �  // �3 m  // f // 10 // 1
        4, // ����� ��� �   o  // ppm  // f // 11 // 1
        4, // ��������� �����  // � it  // f // 12 // 1
        4, // ����� ������ 1  // �/��� � n  // f // 13 // 1
        4, // ����� ������ 2  // �/��� � n  // f // 14 // 1
        4, // ������ �� ������ ��  // �3/��� c  // f // 15 // 1
        4, // �1 e  // ppm  // f // 16 // 1
        4, // �2 sdfsdfsdf  // ppm  // f // 17 // 1
        4, // �3 e  // ppm  // f // 18 // 1
        4, // H2  // ppm  // f // 19 // 1
        4, // �4  // ppm fs  // f // 20 // 1
        4, // �5  // ppm  // f // 21 // 1
        4, // ���.�������� �������  // �/���  // f // 22 // 1
        4, // ��� 2 �   o  // ���/�  // f // 23 // 1
        4, // �������� �� ����  // � it  // f // 24 // 1
        4, // ����� ������� ����  // ���  // f // 25 // 1
        4, // ��������� �������  // $/m  // f // 26 // 1
        4, // DEXP  // /Pa  // f // 27 // 1
        4, // DEXC � ������ �����.  // a  // f // 28 // 1
        4, // DEXCN ������ ������  // /Pa  // f // 29 // 1
        4, // �����.�����.��������  // ��/�3 m  // f // 30 // 1
        4, // ������ �� ����� ��  // �3/��� c  // f // 31 // 1
        4, // ������ �������� ��  // �3/��� c  // f // 32 // 1
        4, // ��������� �������� �  // ��/�3 m  // f // 33 // 1
        4, // ����������� ��������  // ���  // f // 34 // 1
        4, // ����� ������ ����  // ���  // l // 35 // 1
        4, // �������� ������ ����  // �� t  // l // 36 // 1
        4, // ���������� �����(��)  // ���  // f // 37 // 1
        4, // ���������� �����(��)  // ���  // f // 38 // 1
        4, // ����.����.����� ����  // � it  // f // 39 // 1
        4, // ���������� �����(��)  // ���  // f // 40 // 1
        4, // �2...�6 / �1...�6  // nit  // f // 41 // 1
        4, // �1...�2 / �3...�6  // nit  // f // 42 // 1
        4, // �4...�6 / �3  // // f // 43 // 1
        4, // ����� ������� 1  // �3 m  // f // 44 // 1
        4, // ����� ������� 2  // �3 m  // f // 45 // 1
        4, // ����� ������� 3    // �3 m  // f // 46 // 1
        4, // ����� ������� 4  o  // �3 m  // f // 47 // 1
        4, // ����� ������� 5  // �3  // f // 48 // 1
        4, // ����� ���.������  // �3  // f // 49 // 1
        4, // ����.� ���� ���.���  // ��  // f // 50 // 1
        4, // ����� ���� ��������  // �3  // f // 51 // 1
        4, // ����� ����� ������  // ���  // l // 52 // 1
        4, // ������� ����� �����.  // �  // f // 53 // 1
        4, // ������� ������  // � c  // f // 54 // 1
        4, // ������� ������������  // �  // f // 55 // 1
        4, // ���������� �����(��)  // ���  // f // 56 // 1
        4, // ����� �������� � ��.  // �3 m  // f // 57 // 1
        4, // ���.����. ��������  // ppm  // f // 58 // 1
        4, // ����� � ������ ����  // �3 m  // f // 59 // 1
        4, // ���.����. � ������ �  // ppm  // f // 60 // 1
        4, // �������� � ��������  // �/���  // f // 61 // 1
        4, // ���.����. � ��������  // ppm  // f // 62 // 1
        4, // ����.����. �� ������  // ��  // f // 63 // 1
        4, // ����.����. �� ����a�  // ��/�2 �  // f // 64 // 1
        4, // ����.����. �� ������  // �  // f // 65 // 1
        4, // ����.����. �� ������  // �� 2 m �  // f // 66 // 1
        4, // ����.�������� ������  // ��  // f // 67 // 1
        4, // �������� �������� ��  // �/���  // f // 68 // 1
        4, // ���.����. � ������.  // ppm  // f // 69 // 1
        4, // ���.����. ���������  // ppm  // f // 70 // 1
        4, // ����.����.�����:Dexp  // ��/�3  // f // 71 // 1
        4, // ��� ������  ������  // � m  // f // 72 // 1
        2, // ����� �����  // // i // 73 // 1
        4, // ������� ������ �����  // �  // f // 74 // 1
        4, // ����� ������ �����  // ��� m/yy  // l // 75 // 1
        4, // ������� ������� ��.�  // � :mm:ss  // f // 76 // 1
        4, // ������ ���/��� ���  // �3 ��  // f // 77 // 1
        2, // ������ �������  // // i // 78 // 1
        4, // ������ ������� /���  // ��/�3  // f // 79 // 1
        4, // ��������� ����� ��  // ��/�3 m  // f // 80 // 1
        4, // ������� ����� ��  // � ch  // f // 81 // 1
        4, // �������� ��������  // ��*��� �  // f // 82 // 1
        4, // ���������� ������ ��  // �� �2 m  // f // 83 // 1
        4, // ����.���������� ����  // ��/�3 m  // f // 84 // 1
        4, // ����.������� ������.  // ��/�3 m  // f // 85 // 1
        12, // ��� ������ ensity  // /cc  // c // 86 // 1
        4, // ��������� ������  // $ cc  // f // 87 // 1
        4, // ������� ������ ty  // � ch  // f // 88 // 1
        4, // Sigma:���������� ��  // 3/��� r  // f // 89 // 1
        4, // Sigma:��������� �� 3  // 3/���  // f // 90 // 1
        4, // Sigma:��������� ����  // // f // 91 // 1
        4, // Sigma:���������� ��  // % /�  // f // 92 // 1
        4, // ������� ������� y  // �2 m  // f // 93 // 1
        4, // ����������. ������ 1  // �3/��� r  // f // 94 // 1
        4, // ����� ������� 9  // �3 ��  // f // 95 // 1
        4, // �� (�����-�������) �  // API  // f // 96 // 1
        4, // ��������� ����.�� ��  // ppm  // f // 97 // 1
        4, // ���������������� ���  // ppm  // f // 98 // 1
        4, // ����������� ��������  // ppm  // f // 99 // 1
        4, // ������� ������ �����  // �  // f // 100 // 1
        4, // ������� ����� ������  // � c  // f // 101 // 1
        4, // ������ �� ������  // �*�  // f // 102 // 1
        2, // ��� ������ ode  // // i // 103 // 1
        4, // ����� ��� ����  // ���  // f // 104 // 1
        4, // Sigm:����.����.�����  // ��/�3  // f // 105 // 1
        4, // ����� �� �����  // ��� �� nd  // f // 106 // 1
        2, // ���� ��� ��������  // �� �  // i // 107 // 1
        2, // ���� ������ ��������  // �� �  // i // 108 // 1
        2, // ���� ��� ��������  // �� �  // i // 109 // 1
        2, // ���� ������ ��������  // �� �  // i // 110 // 1
        2, // ���� � ����� �����  // �� �  // i // 111 // 1
        2, // ��������� �������  // ipe  // i // 112 // 1
        2, // ���� �� ����� �����  // �� �  // i // 113 // 1
        4, // H2S ������ 1 ����  // ppm  // f // 114 // 1
        4, // ��� ����� ��� �����.  // ��  // f // 115 // 1
        4, // ��� ����� ��� ����.  // ��  // f // 116 // 1
        4, // �������. ��������� t  // �3 m m  // f // 117 // 1
        4, // �������. ��������� t  // �3 m m  // f // 118 // 1
        4, // �������. ������� ent  // �3 m m  // f // 119 // 1
        4, // ����.������/�������.  // ppm  // f // 120 // 1
        4, // ������ �� �� �������  // �3 10��� �  // f // 121 // 1
        4, // ������ �� �� �������  // �3 � m  // f // 122 // 1
        4, // ����� ��� �� �������  // ���  // f // 123 // 1
        4, // �������� ���������  // ppm  // f // 124 // 1
        32, // ����������� re  // si  // c // 125 // 1
        9, // ���������������  // // c // 126 // 1
        4, // ���������������� ���  // ppm  // f // 127 // 1
        4, // ��������� ��������  // ��/�3 m  // f // 128 // 1
        4, // ����� ������ ���.��.  // ��� ��.��  // f // 129 // 1
        4, // ����� ������ ���.���  // ��� jt  // f // 130 // 1
        2, // ���.���� ������ ���.  // �� ��  // i // 131 // 1
        2, // ���.���� ��� �����.  // �� ��  // i // 132 // 1
        4, // ����� ��������� ����  // ���  // f // 133 // 1
        4, // ��������� ���.������  // ��*�  // f // 134 // 1
        4, // ����� ������ 3  // �/��� �  // f // 135 // 1
        4, // ������ �� ���������  // �3 ��� ur  // f // 136 // 1
        4, // ��4 / �1...�6 0 �)  // % 10� m  // f // 137 // 1
        4, // ����� ���� (�������)  // �3 � m  // f // 138 // 1
        4, // ����� �����.������.  // ���  // f // 139 // 1
        4, // ����.���������� ���  // � c  // f // 140 // 1
        4, // ����� �����.�������  // ���  // f // 141 // 1
        4, // ���-�� ���������� ��  // �3 m  // f // 142 // 1
        4, // ���������� ����.����  // �/���  // f // 143 // 1
        4, // ����� �.������� ����  // ���  // f // 144 // 1
        4, // ����� ������� 10 ���  // �3  // f // 145 // 1
        4, // ����� ������� 11 ���  // �3 e  // f // 146 // 1
        4, // ����� �.���������� �  // ���  // f // 147 // 1
        31, // ���������� res.Loss  // si  // c // 148 // 1
        4, // ����� ������� 12  // �3 �  // f // 149 // 1
        2, // �������� ���� �����  // �� �� 9  // i // 150 // 1
        4, // ����� ������� ����  // ���  // f // 151 // 1
        4, // ����� �1...�6  // ppm  // f // 152 // 1
        4, // �1...�2 / �5...�6  // // f // 153 // 1
        4, // H2S  // ppm  // f // 154 // 1
        4, // ������������� �� ��  // // f // 155 // 1
        4, // ������������� �� ���  // // f // 156 // 1
        4, // ����� ������� ���  // ���  // f // 157 // 1
        4, // ����� ���������� ���  // ���  // f // 158 // 1
        4, // ����� ����������  // ���  // f // 159 // 1
        4, // ����� �������� ����  // ���  // f // 160 // 1
        4, // ����� ����������� ��  // ���  // f // 161 // 1
        4, // ����� ��� ����  // ���  // f // 162 // 1
        4, // ����� ��� ����  // ���  // f // 163 // 1
        4, // ����� ��� ����  // ���  // f // 164 // 1
        4, // ����� ������� ����  // ���  // f // 165 // 1
        4, // ��������� ��� 1  // ��/�3  // f // 166 // 1
        4, // ��������� ��� 2  // ��/�3  // f // 167 // 1
        4, // ��������� ��� 3 �  // ��/�3  // f // 168 // 1
        4, // ��������� ��� 4 ����  // ��/�3 m  // f // 169 // 1
        4, // ��������� ��� 5  // ��/�3  // f // 170 // 1
        4, // ����������� ��� 1 �  // ��� �  // f // 171 // 1
        4, // ����������� ��� 2 �  // ��� �  // f // 172 // 1
        4, // ����������� ��� 3 ��  // ��� ATA\  // f // 173 // 1
        4, // ����������� ��� 4 �.  // ���  // f // 174 // 1
        4, // ����������� ��� 5  // ���  // f // 175 // 1
        4, // �������  // ppm  // f // 176 // 1
        4, // �2' ������ ��� ���6  // ppm  // f // 177 // 1
        4, // ������� ������ �����  // �  // f // 178 // 1
        4, // H2S ������ 2 ���� �.  // ppm  // f // 179 // 1
        4, // Dexp:������ ����.���  // ��/�3  // f // 180 // 1
        4, // Sigm:������ ����.���  // ��/�3  // f // 181 // 1
        4, // ����� ���������� �  // ���  // f // 182 // 1
        4, // ����� �������� ���  // ���  // f // 183 // 1
        4, // ����� �����������  // ���  // f // 184 // 1
        4, // ����� ���  ����  // ���  // f // 185 // 1
        4, // ����� ���������� � u  // ���  // f // 186 // 1
        4, // ����� ������� ����  // ���  // f // 187 // 1
        4, // �������� �����.�����  // ��/�3  // f // 188 // 1
        4, // �����.����.������  // ��/�2  // f // 189 // 1
        2, // ����������� ����� on  // // i // 190 // 1
        4, // �����.�������� �����  // �/���  // f // 191 // 1
        4, // ������� ������������  // �  // f // 192 // 1
        4, // �����������  // ���  // f // 193 // 1
        4, // ������  // ���  // f // 194 // 1
        4, // �����  // ���  // f // 195 // 1
        4, // �������  // % m  // f // 196 // 1
        4, // ������ �� ����� ----  // �*�  // f // 197 // 1
        4, // ����.����.����� ����  // � gC  // f // 198 // 1
        4, // ��������� ������  // ��/�3  // f // 199 // 1
        4, // ����������� ������  // ���  // f // 200 // 1
        4, // ��4 � 9  // ppm  // f // 201 // 1
        4, // �1 / �1...�6  // %  // f // 202 // 1
        4, // �2 / �1...�6  // %  // f // 203 // 1
        4, // �3 / �1...�6  // %  // f // 204 // 1
        4, // �������.�����.�����  // ��/�3  // f // 205 // 1
        4, // �4 / �1...�6  // %  // f // 206 // 1
        4, // �5 / �1...�6  // %  // f // 207 // 1
        4, // �6 / �1...�6  // %  // f // 208 // 1
        4, // �6 e  // ppm  // f // 209 // 1
        4, // ��������� ����������  // �/���2  // f // 210 // 1
        4, // �������� ����������  // �/���  // f // 211 // 1
        2, // ��������������� ����  // ode  // i // 212 // 1
        4, // ����� ��� �� �������  // // l // 213 // 1
        4, // ����� ��� �� �������  // // l // 214 // 1
        4, // ��4 .�������� ������  // ppm  // f // 215 // 1
        4, // �1 �� �����  // ppm  // f // 216 // 1
        4, // �2 �� �����  // ppm  // f // 217 // 1
        4, // �3 �� �����  // ppm  // f // 218 // 1
        4, // �4 �� �����  // ppm  // f // 219 // 1
        4, // �5 �� �����  // ppm  // f // 220 // 1
        4, // �6 �� �����  // ppm  // f // 221 // 1
        4, // ����� ����� �1...�6  // ppm  // f // 222 // 1
        4, // ��4/�1...�6  // %  // f // 223 // 1
        4, // �2...�3 / �4...�6  // // f // 224 // 1
        4, // �1 / �2...�6  // // f // 225 // 1
        4, // CO2  // ppm  // f // 226 // 1
        4, // ������� ���� �� ����  // ���  // f // 227 // 1
        4, // �������� ��� ������  // ppm  // f // 228 // 1
        4, // ����������� ����� .  // ���  // f // 229 // 1
        4, // ����������� ����� 1  // ���  // f // 230 // 1
        4, // ����������� ����� 2  // ���  // f // 231 // 1
        10, // ������� ����� �����  // // c // 232 // 1
        4, // ��� ������  // // l // 233 // 1
        4, // ��� ��  � G � G �<� L // // l // 234 // 1
        4, // �������� �����������  // �/���  // f // 235 // 1
        4, // ����� ������� 6  // �3  // f // 236 // 1
        4, // ����� ������� 7  // �3  // f // 237 // 1
        4, // ����� ������� 8  // �3  // f // 238 // 1
        4, // ����� �����.��������  // �3  // f // 239 // 1
        4, // Dexp:��������� ����.  // ppm  // f // 240 // 1
        4, // Sigm:��������� ����.  // ppm  // f // 241 // 1
        4, // ��� �� ����� ��� min  // ��  // f // 242 // 1
        4, // ��� �� ����� ��� max  // ��  // f // 243 // 1
        4, // ������� ������  // ��/�  // f // 244 // 1
        4, // ����.����.����������  // % �  // f // 245 // 1
        4, // ��� �������� �����.  // ��  // f // 246 // 1
        4, // Dexp:����� ����.���.  // ��/�3  // f // 247 // 1
        4, // Sigm:����� ����.���.  // ��/�3  // f // 248 // 1
        4, // ��5  // ppm  // f // 249 // 1
        4, // ��5 / �1...�6  // %  // f // 250 // 1
        4, // ��5  // ppm  // f // 251 // 1
        4, // ��5 / �1...�6  // %  // f // 252 // 1
        4, // ������ ������ (max)  // �*�  // f // 253 // 1
        20, // ��������� ���.������  // �/�3  // c // 254 // 1
    };
};
