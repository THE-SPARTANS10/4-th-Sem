library IEEE;
use IEEE.std_logic_1164.all;

entity JKFF is
end entity;

architecture tb of JKFF is
	component JK is
		port ( 
        J,K,CLK,RST : in STD_LOGIC; 
      	Q,QB : out STD_LOGIC);
end component ;

signal J, K, CLK, RST, Q, QB : STD_LOGIC;

begin
uut: JK port map(J,K,CLK,RST,Q,QB);

Clock : process
begin
  CLK <= '0';
  wait for 10 ns;
  CLK <= '1';
  wait for 10 ns;
end process;

stim : process
begin
  RST<='1';
  J <= '0';
  K <= '0';
  wait for 40 ns;
  RST <= '0';
  J <= '0';
  K <= '0';
  wait for 20 ns;
  RST <= '0';
  J <= '0';
  K <= '1';
  wait for 20 ns;
  RST <= '0';
  J <= '1';
  K <= '0';
  wait for 20 ns;
  RST <= '0';
  J <= '1';
  K <= '1';
  wait for 40 ns;
end process;
end tb;