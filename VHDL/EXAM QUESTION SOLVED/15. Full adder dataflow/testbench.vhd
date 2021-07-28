library IEEE;
use IEEE.std_logic_1164.all;

entity testbench is
--empty
end testbench;

architecture tb of testbench is

--DUT Component
component full_adder is
port(
 a : in std_logic;
 b : in std_logic;
 cin : in std_logic;
 s : out std_logic;
 cout : out std_logic);
end component;
 
signal a_in, b_in, cin_in, s_out, cout_out: std_logic;
 
begin
 
 --Connect DUT
  DUT: full_adder port map(a_in, b_in, cin_in, s_out, cout_out);
 
 process
 begin
  a_in <= '0';
  b_in <= '0';
  cin_in <= '0';
  wait for 1 ns;
  
  a_in <= '0';
  b_in <= '0';
  cin_in <= '1';
  wait for 1 ns;
  
  a_in <= '0';
  b_in <= '1';
  cin_in <= '0';
  wait for 1 ns;
  
  a_in <= '0';
  b_in <= '1';
  cin_in <= '1';
  wait for 1 ns;
  
  a_in <= '1';
  b_in <= '0';
  cin_in <= '0';
  wait for 1 ns;
  
  a_in <= '1';
  b_in <= '0';
  cin_in <= '1';
  wait for 1 ns;
  
  a_in <= '1';
  b_in <= '1';
  cin_in <= '0';
  wait for 1 ns;
  
  a_in <= '1';
  b_in <= '1';
  cin_in <= '1';
  wait for 1 ns;
   
  wait;
 end process;
end tb;