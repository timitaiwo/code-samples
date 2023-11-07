# Data Processing example
Given an input file of the below structure: <br>

_[stock_name] [trading_interval] [volume_traded] [High] [Low]_ e.g <br> HDI.DF 1 700 448.48 125.47

Return an output file of the below format. Note that the output could either be printed to terminal or stored in a file.

_[stock_name] [trading_interval] [%volume_traded_in_interval/total_volume_for_the_day] <br>
\#<br>
[stock_name] [highest_for_the_day] [lowest_for_the_day]_

For example, given a file

HDI.DF 1 700 448.48 125.47<br>
DFS.SD 1 85 254.48 154.78<br>
HDI.DF 2 1000 548.37 244.45<br>
DFS.SD 2 35 355.41 254.54<br>

The output would be

HDI.DF 1 41<br>
DFS.SD 1 71<br>
HDI.DF 2 59<br>
DFS.SD 2 29<br>
\#<br>
HDI.DF 548.37 125.47<br>
DFS.SD 355.41 154.78<br>
