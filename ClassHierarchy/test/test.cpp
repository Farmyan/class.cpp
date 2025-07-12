#include <gtest/gtest.h>
#include "Association.h"
#include "BCorp.h"
#include "CharitableTrust.h"
#include "CJSC.h"
#include "Corporation.h"
#include "Foundation.h"
#include "IGO.h"
#include "LLC.h"
#include "OJSC.h"
#include "PublicCorporation.h"
#include "SocialEnterprise.h"
#include "SoleProprietorship.h"
#include "StateAgency.h"
//Association
TEST(AssociationTest, ABA) {
    Association org("ABA", "USA", "Legal Profession", "American Bar Association supports lawyers");
    EXPECT_EQ(org.getDescription(), "Association: ABA from USA focused on American Bar Association supports lawyers");
}

TEST(AssociationTest, NBA) {
    Association org("NBA", "USA", "Sports", "National Basketball Association");
    EXPECT_EQ(org.getDescription(), "Association: NBA from USA focused on National Basketball Association");
}

TEST(AssociationTest, AMA) {
    Association org("AMA", "USA", "Medical", "American Medical Association advocates for physicians");
    EXPECT_EQ(org.getDescription(), "Association: AMA from USA focused on American Medical Association advocates for physicians");
}

TEST(AssociationTest, AARP) {
    Association org("AARP", "USA", "Advocacy", "Advocating for people aged 50 and over");
    EXPECT_EQ(org.getDescription(), "Association: AARP from USA focused on Advocating for people aged 50 and over");
}

TEST(AssociationTest, NEA) {
    Association org("NEA", "USA", "Education", "National Education Association supports educators");
    EXPECT_EQ(org.getDescription(), "Association: NEA from USA focused on National Education Association supports educators");
}
//BCorp 
TEST(BCorpTest, KingArthur) {
    BCorp org("King Arthur Baking Company", "USA", "Food Manufacturing", "Flour & baking products; community baking education");
    EXPECT_EQ(org.getDescription(), "BCorp: King Arthur Baking Company from USA focused on Flour & baking products; community baking education");
}
TEST(BCorpTest, Leesa) {
    BCorp org("Leesa", "USA", "Furniture / Mattresses", "Direct-to-consumer mattresses; 'one sold, one donated' model");
    EXPECT_EQ(org.getDescription(), "BCorp: Leesa from USA focused on Direct-to-consumer mattresses; 'one sold, one donated' model");
}
TEST(BCorpTest, Kickstarter) {
    BCorp org("Kickstarter", "USA", "Crowdfunding / Online Platform", "Funding creative and entrepreneurial projects");
    EXPECT_EQ(org.getDescription(), "BCorp: Kickstarter from USA focused on Funding creative and entrepreneurial projects");
}
TEST(BCorpTest, Patagonia) {
    BCorp org("Patagonia", "USA", "Apparel & Outdoor Gear", "Environmental activism, sustainable apparel production");
    EXPECT_EQ(org.getDescription(), "BCorp: Patagonia from USA focused on Environmental activism, sustainable apparel production");
}
TEST(BCorpTest, Bombas) {
    BCorp org("Bombas", "USA", "Apparel", "Comfortable socks and apparel; “buy one, donate one” for the homeless");
    EXPECT_EQ(org.getDescription(), "BCorp: Bombas from USA focused on Comfortable socks and apparel; “buy one, donate one” for the homeless");
}

//CharitableTrust
TEST(CharitableTrustTest, MyForestArmenia) {
    CharitableTrust org("My Forest Armenia", "Armenia", "Environmental Conservation", "Reforestation and climate action");
    EXPECT_EQ(org.getDescription(), "CharitableTrust: My Forest Armenia from Armenia focused on Reforestation and climate action");
}
TEST(CharitableTrustTest, UNICEF) {
    CharitableTrust org("UNICEF", "International", "Child Welfare", "Protecting children's rights and providing emergency aid");
    EXPECT_EQ(org.getDescription(), "CharitableTrust: UNICEF from International focused on Protecting children's rights and providing emergency aid");
}
TEST(CharitableTrustTest, DoctorsWithoutBorders) {
    CharitableTrust org("Doctors Without Borders", "International", "Healthcare", "Providing emergency medical aid worldwide");
    EXPECT_EQ(org.getDescription(), "CharitableTrust: Doctors Without Borders from International focused on Providing emergency medical aid worldwide");
}
TEST(CharitableTrustTest, WFP) {
    CharitableTrust org("World Food Programme", "UN", "Food Security", "Combating hunger and food insecurity globally");
    EXPECT_EQ(org.getDescription(), "CharitableTrust: World Food Programme from UN focused on Combating hunger and food insecurity globally");
}
TEST(CharitableTrustTest, Oxfam) {
    CharitableTrust org("Oxfam", "UK", "Poverty Alleviation", "Fighting inequality and poverty around the world");
    EXPECT_EQ(org.getDescription(), "CharitableTrust: Oxfam from UK focused on Fighting inequality and poverty around the world");
}

//CJSC 
TEST(CJSCTest, Ameriabank) {
    CJSC org("Ameriabank", "Armenia", "Banking", "Retail and corporate banking services");
    EXPECT_EQ(org.getDescription(), "CJSC: Ameriabank from Armenia focused on Retail and corporate banking services");
}
TEST(CJSCTest, Ardshinbank) {
    CJSC org("Ardshinbank", "Armenia", "Financial Services", "Comprehensive financial solutions for individuals and businesses");
    EXPECT_EQ(org.getDescription(), "CJSC: Ardshinbank from Armenia focused on Comprehensive financial solutions for individuals and businesses");
}
TEST(CJSCTest, VTBBank) {
    CJSC org("VTB Bank Armenia", "Armenia", "Banking", "Part of VTB Group offering banking services");
    EXPECT_EQ(org.getDescription(), "CJSC: VTB Bank Armenia from Armenia focused on Part of VTB Group offering banking services");
}
TEST(CJSCTest, INCORE) {
    CJSC org("INCORE", "Armenia", "IT Services", "Custom software development and consulting");
    EXPECT_EQ(org.getDescription(), "CJSC: INCORE from Armenia focused on Custom software development and consulting");
}
TEST(CJSCTest, SOURCIO) {
    CJSC org("SOURCIO", "Armenia", "Software Development", "Outsourcing and enterprise software solutions");
    EXPECT_EQ(org.getDescription(), "CJSC: SOURCIO from Armenia focused on Outsourcing and enterprise software solutions");
}

//Corporation 
TEST(CorporationTest, Amazon) {
    Corporation org("Amazon", "USA", "E-Commerce", "Global online retail and cloud services provider");
    EXPECT_EQ(org.getDescription(), "Corporation: Amazon from USA focused on Global online retail and cloud services provider");
}
TEST(CorporationTest, Walmart) {
    Corporation org("Walmart", "USA", "Retail", "Hypermarkets and consumer goods");
    EXPECT_EQ(org.getDescription(), "Corporation: Walmart from USA focused on Hypermarkets and consumer goods");
}
TEST(CorporationTest, Microsoft) {
    Corporation org("Microsoft", "USA", "Technology", "Software, cloud computing, and AI solutions");
    EXPECT_EQ(org.getDescription(), "Corporation: Microsoft from USA focused on Software, cloud computing, and AI solutions");
}
TEST(CorporationTest, CocaCola) {
    Corporation org("The Coca-Cola Company", "USA", "Beverages", "Non-alcoholic beverage production and marketing");
    EXPECT_EQ(org.getDescription(), "Corporation: The Coca-Cola Company from USA focused on Non-alcoholic beverage production and marketing");
}
TEST(CorporationTest, Ford) {
    Corporation org("Ford Motor Company", "USA", "Automotive", "Manufacturing cars and mobility solutions");
    EXPECT_EQ(org.getDescription(), "Corporation: Ford Motor Company from USA focused on Manufacturing cars and mobility solutions");
}

//Foundation 
TEST(FoundationTest, BritishHeart) {
    Foundation org("British Heart Foundation", "UK", "Medical Research", "Cardiovascular disease research and education");
    EXPECT_EQ(org.getDescription(), "Foundation: British Heart Foundation from UK focused on Cardiovascular disease research and education");
}
TEST(FoundationTest, Rolex) {
    Foundation org("Rolex Foundation", "Switzerland", "Philanthropy", "Supporting science, exploration, and the arts");
    EXPECT_EQ(org.getDescription(), "Foundation: Rolex Foundation from Switzerland focused on Supporting science, exploration, and the arts");
}
TEST(FoundationTest, Ikea) {
    Foundation org("IKEA Foundation", "Netherlands", "Humanitarian Aid", "Improving opportunities for children and families");
    EXPECT_EQ(org.getDescription(), "Foundation: IKEA Foundation from Netherlands focused on Improving opportunities for children and families");
}
TEST(FoundationTest, Carlsberg) {
    Foundation org("Carlsberg Foundation", "Denmark", "Science and Culture", "Supporting basic scientific research and cultural projects");
    EXPECT_EQ(org.getDescription(), "Foundation: Carlsberg Foundation from Denmark focused on Supporting basic scientific research and cultural projects");
}
TEST(FoundationTest, Heineken) {
    Foundation org("Heineken Africa Foundation", "Netherlands", "Healthcare", "Improving health in African communities");
    EXPECT_EQ(org.getDescription(), "Foundation: Heineken Africa Foundation from Netherlands focused on Improving health in African communities");
}

//IGO 
TEST(IGOTest, AU) {
    IGO org("African Union", "Africa", "Political Integration", "Promoting unity and development among African states");
    EXPECT_EQ(org.getDescription(), "IGO: African Union from Africa focused on Promoting unity and development among African states");
}
TEST(IGOTest, EU) {
    IGO org("European Union", "Europe", "Economic and Political Union", "Integration of European countries and legislation");
    EXPECT_EQ(org.getDescription(), "IGO: European Union from Europe focused on Integration of European countries and legislation");
}
TEST(IGOTest, UN) {
    IGO org("United Nations", "International", "Global Governance", "Maintaining international peace and promoting cooperation");
    EXPECT_EQ(org.getDescription(), "IGO: United Nations from International focused on Maintaining international peace and promoting cooperation");
}
TEST(IGOTest, WTO) {
    IGO org("World Trade Organization", "International", "Trade", "Regulating international trade and resolving disputes");
    EXPECT_EQ(org.getDescription(), "IGO: World Trade Organization from International focused on Regulating international trade and resolving disputes");
}
TEST(IGOTest, WorldBank) {
    IGO org("World Bank", "International", "Development", "Providing loans and grants to developing countries");
    EXPECT_EQ(org.getDescription(), "IGO: World Bank from International focused on Providing loans and grants to developing countries");
}

//LLC 
TEST(LLCTest, GrandTobacco) {
    LLC org("Grand Tobacco", "Armenia", "Tobacco Industry", "Manufacturing and distribution of tobacco products");
    EXPECT_EQ(org.getDescription(), "LLC: Grand Tobacco from Armenia focused on Manufacturing and distribution of tobacco products");
}
TEST(LLCTest, Phoenix) {
    LLC org("Phoenix", "USA", "Energy", "Renewable energy and smart grids");
    EXPECT_EQ(org.getDescription(), "LLC: Phoenix from USA focused on Renewable energy and smart grids");
}
TEST(LLCTest, Sparkster) {
    LLC org("Sparkster", "USA", "Technology", "Decentralized cloud platforms and smart software tools");
    EXPECT_EQ(org.getDescription(), "LLC: Sparkster from USA focused on Decentralized cloud platforms and smart software tools");
}
TEST(LLCTest, AfterLife) {
    LLC org("AfterLife", "USA", "Entertainment", "Virtual memorial and legacy services");
    EXPECT_EQ(org.getDescription(), "LLC: AfterLife from USA focused on Virtual memorial and legacy services");
}
TEST(LLCTest, Seekit) {
    LLC org("Seekit", "India", "Electronics", "Smart tracking devices and IoT solutions");
    EXPECT_EQ(org.getDescription(), "LLC: Seekit from India focused on Smart tracking devices and IoT solutions");
}

//PublicCorporation
TEST(PublicCorporationTest, Apple) {
    PublicCorporation org("Apple", "USA", "Technology", "Consumer electronics, software, and services");
    EXPECT_EQ(org.getDescription(), "PublicCorporation: Apple from USA focused on Consumer electronics, software, and services");
}
TEST(PublicCorporationTest, McDonalds) {
    PublicCorporation org("McDonald's", "USA", "Fast Food", "Global restaurant chain specializing in burgers");
    EXPECT_EQ(org.getDescription(), "PublicCorporation: McDonald's from USA focused on Global restaurant chain specializing in burgers");
}
TEST(PublicCorporationTest, AstraZeneca) {
    PublicCorporation org("AstraZeneca", "UK", "Pharmaceuticals", "Research and production of medicines");
    EXPECT_EQ(org.getDescription(), "PublicCorporation: AstraZeneca from UK focused on Research and production of medicines");
}
TEST(PublicCorporationTest, Citigroup) {
    PublicCorporation org("Citigroup", "USA", "Financial Services", "Banking and investment services worldwide");
    EXPECT_EQ(org.getDescription(), "PublicCorporation: Citigroup from USA focused on Banking and investment services worldwide");
}
TEST(PublicCorporationTest, ExxonMobil) {
    PublicCorporation org("ExxonMobil", "USA", "Oil & Gas", "Exploration, production, and refining of petroleum");
    EXPECT_EQ(org.getDescription(), "PublicCorporation: ExxonMobil from USA focused on Exploration, production, and refining of petroleum");
}

//SocialEnterprise 
TEST(SocialEnterpriseTest, WarbyParker) {
    SocialEnterprise org("Warby Parker", "USA", "Eyewear", "Buy a pair, give a pair program for glasses");
    EXPECT_EQ(org.getDescription(), "SocialEnterprise: Warby Parker from USA focused on Buy a pair, give a pair program for glasses");
}
TEST(SocialEnterpriseTest, FIGS) {
    SocialEnterprise org("FIGS", "USA", "Healthcare Apparel", "Premium scrubs and medical uniforms for healthcare professionals");
    EXPECT_EQ(org.getDescription(), "SocialEnterprise: FIGS from USA focused on Premium scrubs and medical uniforms for healthcare professionals");
}
TEST(SocialEnterpriseTest, TomsShoes) {
    SocialEnterprise org("TOMS Shoes", "USA", "Footwear", "One for one giving model for shoes");
    EXPECT_EQ(org.getDescription(), "SocialEnterprise: TOMS Shoes from USA focused on One for one giving model for shoes");
}
TEST(SocialEnterpriseTest, Cooperative) {
    SocialEnterprise org("The Cooperative Group", "UK", "Retail", "Member-owned ethical retail business");
    EXPECT_EQ(org.getDescription(), "SocialEnterprise: The Cooperative Group from UK focused on Member-owned ethical retail business");
}
TEST(SocialEnterpriseTest, Microfinance) {
    SocialEnterprise org("Grameen Bank", "Bangladesh", "Finance", "Microloans for poverty alleviation");
    EXPECT_EQ(org.getDescription(), "SocialEnterprise: Grameen Bank from Bangladesh focused on Microloans for poverty alleviation");
}

//SoleProprietorship 
TEST(SoleProprietorshipTest, Google) {
    SoleProprietorship org("Google (Early)", "USA", "Search Engine", "Started as a sole proprietorship by Larry Page");
    EXPECT_EQ(org.getDescription(), "SoleProprietorship: Google (Early) from USA focused on Started as a sole proprietorship by Larry Page");
}
TEST(SoleProprietorshipTest, Dyson) {
    SoleProprietorship org("Dyson", "UK", "Consumer Electronics", "Founded by James Dyson, known for vacuum tech");
    EXPECT_EQ(org.getDescription(), "SoleProprietorship: Dyson from UK focused on Founded by James Dyson, known for vacuum tech");
}
TEST(SoleProprietorshipTest, Twitch) {
    SoleProprietorship org("Twitch", "USA", "Streaming", "Originally started independently before acquisition");
    EXPECT_EQ(org.getDescription(), "SoleProprietorship: Twitch from USA focused on Originally started independently before acquisition");
}
TEST(SoleProprietorshipTest, JonesBakery) {
    SoleProprietorship org("Jones Bakery", "USA", "Food & Bakery", "Local family-run bakery");
    EXPECT_EQ(org.getDescription(), "SoleProprietorship: Jones Bakery from USA focused on Local family-run bakery");
}
TEST(SoleProprietorshipTest, PeterMuller) {
    SoleProprietorship org("Peter Müller Bakery", "Germany", "Bakery", "Traditional artisan baking");
    EXPECT_EQ(org.getDescription(), "SoleProprietorship: Peter Müller Bakery from Germany focused on Traditional artisan baking");
}

//StateAgency 
TEST(StateAgencyTest, ArizonaCommission) {
    StateAgency org("Arizona Corporation Commission", "USA", "Utilities Regulation", "Regulating public utilities and corporations");
    EXPECT_EQ(org.getDescription(), "StateAgency: Arizona Corporation Commission from USA focused on Regulating public utilities and corporations");
}
TEST(StateAgencyTest, CaliforniaEnergy) {
    StateAgency org("California Energy Commission", "USA", "Energy Policy", "Energy planning and innovation in California");
    EXPECT_EQ(org.getDescription(), "StateAgency: California Energy Commission from USA focused on Energy planning and innovation in California");
}
TEST(StateAgencyTest, WisconsinEnergy) {
    StateAgency org("Wisconsin Office of Energy Innovation", "USA", "Energy Efficiency", "Supporting clean energy and infrastructure");
    EXPECT_EQ(org.getDescription(), "StateAgency: Wisconsin Office of Energy Innovation from USA focused on Supporting clean energy and infrastructure");
}
TEST(StateAgencyTest, DepartmentOfPublicService) {
    StateAgency org("Department of Public Service", "USA", "Utilities Oversight", "Overseeing utility rates and safety");
    EXPECT_EQ(org.getDescription(), "StateAgency: Department of Public Service from USA focused on Overseeing utility rates and safety");
}
TEST(StateAgencyTest, NebraskaBoard) {
    StateAgency org("Nebraska Power Review Board", "USA", "Energy", "Approving and regulating electric generation in Nebraska");
    EXPECT_EQ(org.getDescription(), "StateAgency: Nebraska Power Review Board from USA focused on Approving and regulating electric generation in Nebraska");
}
