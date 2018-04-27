# Je pense néanmoins que R est plus facile à utiliser avec le package ggplot2.
# Je vous recommande très fortement d'utiliser l'IDE r-studio et de vous inspirer de ces commandes:
echo "
library(ggplot2)
library(readr)

df <- read_csv("results.csv")
df <- aggregate(df["temps"], by=df[c("algo","serie","taille")], FUN=mean)

ggplot(df, aes(x=taille, y=temps, group=algo, color=algo)) +
    geom_point() + geom_line() +
    facet_grid(. ~ serie) +
    scale_x_log10() + scale_y_log10()
ggsave("test_puissance_r.png", width=12, height=4, units="cm")
" > test_puissance.R
