/*
Problem: 3387. Maximize Amount After Two Days of Conversions

You are given an initial currency and two sets of conversion rates for day 1 and day 2.
You start with 1.0 of the initial currency. You can perform any number of conversions
on day 1 using rates1, followed by any number of conversions on day 2 using rates2.
Return the maximum amount of initialCurrency you can have after both days.

Approach:
1. Build a graph for each day where vertices = currencies, edges = conversion rates.
2. Use Floyd-Warshall to compute maximum conversion rate between every pair of currencies.
3. For day 1, compute the max amount obtainable for each currency starting from initialCurrency.
4. For day 2, for each currency obtained after day 1, compute how much it can convert back
   to initialCurrency.
5. Return the maximum amount obtained after both days.

Time Complexity: O(N^3 + M), where 
    N = number of unique currencies,
    M = number of currency pairs
Space Complexity: O(N^2), for storing conversion rates between all currency pairs
*/

class Solution {
public:
    // Build graph from currency pairs and their rates
    unordered_map<string, unordered_map<string, double>>
    buildGraph(vector<vector<string>>& pairs, vector<double>& rates){
        unordered_map<string, unordered_map<string, double>> graph;
        for(int i = 0; i < pairs.size(); i++) {
            string from = pairs[i][0];
            string to = pairs[i][1];
            double rate = rates[i];
            graph[from][to] = rate;
            graph[to][from] = 1.0 / rate;  // reverse conversion
        }
        return graph;
    }

    // Floyd-Warshall to compute max conversion rate between all pairs
    unordered_map<string, unordered_map<string, double>> FloyddWarshall(
        unordered_map<string, unordered_map<string, double>>& graph){
        
        vector<string> currency;
        for(auto& pair : graph){
            currency.push_back(pair.first);
        }

        unordered_map<string, unordered_map<string, double>> dist;
        for(auto& from : currency){
            for(auto& to : currency){
                if(from == to){
                    dist[from][to] = 1.0;
                }
                else if(graph[from].count(to)){
                    dist[from][to] = graph[from][to];
                }
                else{
                    dist[from][to] = 0.0;
                }
            }
        }

        for(auto& k : currency){
            for(auto& i : currency){
                for(auto& j : currency){
                    dist[i][j] = max(dist[i][j], dist[i][k] * dist[k][j]);
                }
            }
        }
        return dist;
    }

    double maxAmount(string initialCurrency, vector<vector<string>>& pairs1,
                     vector<double>& rates1, vector<vector<string>>& pairs2,
                     vector<double>& rates2) {
        
        // Build graphs for both days
        auto graph1 = buildGraph(pairs1, rates1);
        auto graph2 = buildGraph(pairs2, rates2);

        // Compute max conversion rates between all currencies
        auto day1Rate = FloyddWarshall(graph1);
        auto day2Rate = FloyddWarshall(graph2);

        // Compute max amount obtainable after day 1
        unordered_map<string, double> d1Amount;
        for(auto& money : day1Rate){
            if(day1Rate[initialCurrency].count(money.first)){
                d1Amount[money.first] = day1Rate[initialCurrency][money.first];
            }
        }
        d1Amount[initialCurrency] = 1.0;

        // Compute max amount after day 2 converting back to initialCurrency
        double maxAmount = 1.0;
        for(auto& [currency, amount] : d1Amount){
            if(day2Rate.count(currency)){
                maxAmount = max(maxAmount, amount * day2Rate[currency][initialCurrency]);
            }
        }
        return maxAmount;
    }
};
